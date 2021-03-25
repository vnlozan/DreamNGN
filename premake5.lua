workspace "DreamNGN"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" -- Debug/Windows/x64

-- Include dirs relative to root folder ( solution directory )
IncludeDir = {}
IncludeDir["GLFW"] = "DreamNGN/vendor/GLFW/include"

include "DreamNGN/vendor/GLFW"

project "DreamNGN"
    location "DreamNGN"
    kind "SharedLib" -- dll
    language "C++"

    targetdir ( "bin/" .. outputdir .. "/%{prj.name}" )
    objdir ( "bin-int/" .. outputdir .. "/%{prj.name}" )

    --Precompiled headers
    pchheader "dnpch.h"
    pchsource "DreamNGN/src/dnpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "DN_PLATFORM_WINDOWS",
            "DN_BUILD_DLL"
        }
    
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox" )
        }

    filter "configurations:Debug"
        defines "DN_DEBUG"
        buildoptions "/MDd"
        symbols "On"
    
    filter "configurations:Release"
        defines "DN_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "DN_DIST"
        buildoptions "/MD"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"


    targetdir ( "bin/" .. outputdir .. "/%{prj.name}" )
    objdir ( "bin-int/" .. outputdir .. "/%{prj.name}" )

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "DreamNGN/vendor/spdlog/include",
        "DreamNGN/src"
    }

    links
    {
        "DreamNGN"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "DN_PLATFORM_WINDOWS",
        }
    

    filter "configurations:Debug"
        defines "DN_DEBUG"
        buildoptions "/MDd" -- c/c++ -> code generation -> runtime library : multi-threaded debug dll (/MDd)
        symbols "On"
    
    filter "configurations:Release"
        defines "DN_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "DN_DIST"
        optimize "On"