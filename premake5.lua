workspace "MyGame"
    architecture "x86_64"
    configurations {"Debug", "Release"}
    targetdir "%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.architecture}"
    objdir "%{wks.location}/int/%{cfg.buildcfg}-%{cfg.architecture}"
    includedirs {"%{wks.location}/ThirdParty/include"}
    libdirs {"%{wks.location}/ThirdParty/libs"}
    startproject "Sandbox"

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"

    project "Sandbox"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"
        location "%{wks.location}/Sandbox"

        --includes all files in source folder
        includedirs {"%{wks.location}/Sandbox/src","%{wks.location}/Framework/src"}
	  libdirs {"%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.architecture}"}


        postbuildcommands "{COPY} %{wks.location}/ThirdParty/libs/*.dll %{wks.location}/bin/%{cfg.buildcfg}-%{cfg.architecture}"


        files {
            "%{prj.location}/src/**.h",
            "%{prj.location}/src/**.cpp"
        }

        links {
		"Framework.lib",
        "sfml-system.lib",
        "sfml-main.lib",
        "sfml-window.lib",
        "sfml-graphics.lib",
        "sfml-audio.lib",
        "sfml-system-d.lib",
        "sfml-main-d.lib",
        "sfml-window-d.lib",
        "sfml-graphics-d.lib",
        "sfml-audio-d.lib"
        }

    project "Framework"
        kind "SharedLib"
   	    language "C++"
	    cppdialect "C++17"
	    location "%{wks.location}/Framework"
	    defines {"DllExport"}

        --includes all files in source folder
        includedirs {"%{wks.location}/Framework/src"}

    	  postbuildcommands "{COPY} %{wks.location}/ThirdParty/libs/*.dll %{wks.location}/bin/%{cfg.buildcfg}-%{cfg.architecture}"

        files {
            "%{prj.location}/src/**.h",
            "%{prj.location}/src/**.cpp"
        }

        files {
            "%{prj.location}/Framework/**.h",
            "%{prj.location}/Framework/**.cpp"
        }

        links {
            "sfml-system.lib",
            "sfml-main.lib",
            "sfml-window.lib",
            "sfml-graphics.lib",
            "sfml-audio.lib",
		    "sfml-system-d.lib",
            "sfml-main-d.lib",
            "sfml-window-d.lib",
            "sfml-graphics-d.lib",
            "sfml-audio-d.lib"

        }