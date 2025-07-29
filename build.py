import os
import platform
import sys

system_name = platform.system().lower()
tracy_config = (
    "-DTRACY_ENABLE=OFF "
    "-DTRACY_ON_DEMAND=OFF "
    "-DTRACY_CALLSTACK=OFF "
    "-DTRACY_NO_CALLSTACK=OFF "
    "-DTRACY_NO_CALLSTACK_INLINES=OFF "
    "-DTRACY_ONLY_LOCALHOST=ON "
    "-DTRACY_NO_BROADCAST=OFF "
    "-DTRACY_ONLY_IPV4=OFF "
    "-DTRACY_NO_CODE_TRANSFER=ON "
    "-DTRACY_NO_CONTEXT_SWITCH=ON "
    "-DTRACY_NO_EXIT=OFF "
    "-DTRACY_NO_SAMPLING=ON "
    "-DTRACY_NO_VERIFY=OFF "
    "-DTRACY_NO_VSYNC_CAPTURE=OFF "
    "-DTRACY_NO_FRAME_IMAGE=OFF "
    "-DTRACY_NO_SYSTEM_TRACING=OFF "
    "-DTRACY_PATCHABLE_NOPSLEDS=OFF "
    "-DTRACY_DELAYED_INIT=OFF "
    "-DTRACY_MANUAL_LIFETIME=OFF "
    "-DTRACY_FIBERS=OFF "
    "-DTRACY_NO_CRASH_HANDLER=OFF "
    "-DTRACY_TIMER_FALLBACK=OFF "
    "-DTRACY_LIBUNWIND_BACKTRACE=OFF "
    "-DTRACY_SYMBOL_OFFLINE_RESOLVE=OFF "
    "-DTRACY_LIBBACKTRACE_ELF_DYNLOAD_SUPPORT=OFF "
    "-DTRACY_DEBUGINFOD=ON "
    "-DTRACY_VERBOSE=ON "
    "-DTRACY_DEMANGLE=OFF "
)

generator = " "
if system_name == "windows":
    generator = "-G Ninja "
source = "  .. "
build_cmd = "cmake " + source + generator + " -DCMAKE_BUILD_TYPE=DEBUG " + tracy_config
compile_cmd = "cmake --build . -j256"  # --clean-first "


def build_dir():
    if system_name == "windows":
        return "build_windows"
    else:
        return "build_linux"


def move(file, location):
    location = os.path.abspath(location)
    if system_name == "linux":
        cmd = "mv " + file + " " + location
        os.system(cmd)
    else:
        cmd = "move /Y " + file + " " + location
        os.system(cmd)
        return


def build():
    dir = build_dir()
    if not os.path.exists(dir):
        os.mkdir(dir)
    else:
        os.chdir(dir)
    print("PRESENT DIRECTOR IS ", os.getcwd())
    if os.system(build_cmd) == 0:
        print("CMAKE SUCCEED \n")
        # os.system(" mv compile_commands.json ..")
        move("compile_commands.json", "..")
        print("\n========================= RUNNING MAKE ===================== \n")
        if os.system(compile_cmd) == 0:
            print("COMPILATION SUCCEED \n")
            print("RUNNING APP  \n")
            if os.path.exists("./DEBUG_Profiler_test"):
                print("build sucessfull")
                os.execlp("./DEBUG_Profiler_test", "./DEBUG_Profiler_test")
            else:
                print("build failed")
        else:
            print("cmake  build command failed")
    else:
        print("cmake failed")
    return


build()
