outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Logger"
    kind "StaticLib"
    language "C++"

    targetdir (_WORKING_DIR .. "/bin/" .. outputdir .. "/%{prj.name}")
    objdir (_WORKING_DIR .. "/bin/int/" .. outputdir .. "/%{prj.name}")

    files {
        "src/**.cpp",
        "src/**.h",
        "src/**.ipp",
        "Logger.h"
    }

    includedirs {
        "src/"
    }

    defines {
        
	}

    links {
        
    }

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "On"
        systemversion "latest"
    
    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"