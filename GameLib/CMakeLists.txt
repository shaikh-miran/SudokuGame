project(GameLib)

set(SOURCE_FILES
        MainFrame.h
        MainFrame.cpp
        pch.h
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

        ParseXML.cpp
        ParseXML.h
        Background.cpp
        Background.h
        Declaration.cpp
        Declaration.h
        DeclarationGiven.cpp
        DeclarationGiven.h
        ItemGiven.cpp
        ItemGiven.h
        DeclarationDigit.cpp
        DeclarationDigit.h
        ItemDigit.cpp
        ItemDigit.h
        DeclarationGiven.cpp
        DeclarationGiven.h
        ItemDigit.cpp
        ItemDigit.h
        ItemGiven.cpp
        ItemGiven.h
        DeclarationXray.cpp
        DeclarationXray.h
        DeclarationBackground.cpp
        DeclarationBackground.h
        DeclarationSparty.cpp
        DeclarationSparty.h
        DeclarationContainer.cpp
        DeclarationContainer.h
        ItemContainer.cpp
        ItemContainer.h
        MessageBox.cpp
        MessageBox.h
        YumVisitor.cpp
        YumVisitor.h
        Visitor.cpp
        Visitor.h
        XRayVisitor.cpp
        XRayVisitor.h
        PopUp.cpp
        PopUp.h
        ContainerVisitor.cpp
        ContainerVisitor.h
        Alert.cpp
        Alert.h
        Solution.cpp
        Solution.h
        DigitVisitor.cpp
        DigitVisitor.h
)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)


