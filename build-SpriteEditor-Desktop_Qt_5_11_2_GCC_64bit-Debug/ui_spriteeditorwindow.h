/********************************************************************************
** Form generated from reading UI file 'spriteeditorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRITEEDITORWINDOW_H
#define UI_SPRITEEDITORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpriteEditorWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *drawLayout;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SpriteEditorWindow)
    {
        if (SpriteEditorWindow->objectName().isEmpty())
            SpriteEditorWindow->setObjectName(QStringLiteral("SpriteEditorWindow"));
        SpriteEditorWindow->resize(400, 300);
        centralWidget = new QWidget(SpriteEditorWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 20, 271, 191));
        drawLayout = new QGridLayout(gridLayoutWidget);
        drawLayout->setSpacing(6);
        drawLayout->setContentsMargins(11, 11, 11, 11);
        drawLayout->setObjectName(QStringLiteral("drawLayout"));
        drawLayout->setContentsMargins(0, 0, 0, 0);
        SpriteEditorWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SpriteEditorWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        SpriteEditorWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SpriteEditorWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SpriteEditorWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SpriteEditorWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SpriteEditorWindow->setStatusBar(statusBar);

        retranslateUi(SpriteEditorWindow);

        QMetaObject::connectSlotsByName(SpriteEditorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SpriteEditorWindow)
    {
        SpriteEditorWindow->setWindowTitle(QApplication::translate("SpriteEditorWindow", "SpriteEditorWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpriteEditorWindow: public Ui_SpriteEditorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRITEEDITORWINDOW_H
