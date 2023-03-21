set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.71 COMPONENTS coroutine program_options REQUIRED)

add_executable(bnf_parser
	main.cpp driver/driver.cpp
)
target_include_directories(bnf_parser PRIVATE .)

target_link_libraries(bnf_parser Threads::Threads Boost::coroutine Boost::program_options)