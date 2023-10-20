project(GameLib)

set(SOURCE_FILES MainFrame.h MainFrame.cpp pch.h
        GameView.cpp
        GameView.h
        Game.cpp
        Game.h

        ids.h
        Scoreboard.cpp
        Scoreboard.h

        Sparty.cpp
        Sparty.h
        Item.cpp
        Item.h
        XRay.cpp
        XRay.h

        Scoreboard.cpp
        Scoreboard.h
        ids.h
        ids.cpp
        ParseXML.cpp
        ParseXML.h
        Level.cpp
        Level.h
        Background.cpp
        Background.h

)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)


