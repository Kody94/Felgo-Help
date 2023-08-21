cmake_minimum_required(VERSION 3.16)

project(Test VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Test qml)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Test qml)

enable_testing()


add_executable(TestQString tst_QString.cpp)
add_executable(TestFizzbuzz tst_fizzbuzz.cpp ../fizzbuzz.h ../fizzbuzz.cpp)



target_link_libraries(TestQString Qt${QT_VERSION_MAJOR}::Core Qt6::Test Qt6::Qml)
target_link_libraries(TestFizzbuzz Qt${QT_VERSION_MAJOR}::Core Qt6::Test Qt6::Qml)
install(TARGETS TestQString
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(TARGETS TestFizzbuzz
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

include(GNUInstallDirs)
install(TARGETS TestQString
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(TARGETS TestFizzbuzz
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
