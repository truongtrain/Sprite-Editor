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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpriteEditorWindow
{
public:
    QWidget *centralWidget;
    QPushButton *chooseColorBox;
    QLabel *colorLabel;
    QSlider *sizeSlider;
    QLabel *resolutionLabel;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SpriteEditorWindow)
    {
        if (SpriteEditorWindow->objectName().isEmpty())
            SpriteEditorWindow->setObjectName(QStringLiteral("SpriteEditorWindow"));
        SpriteEditorWindow->resize(1080, 840);
        SpriteEditorWindow->setMinimumSize(QSize(300, 300));
        centralWidget = new QWidget(SpriteEditorWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        chooseColorBox = new QPushButton(centralWidget);
        chooseColorBox->setObjectName(QStringLiteral("chooseColorBox"));
        chooseColorBox->setGeometry(QRect(840, 290, 151, 31));
        colorLabel = new QLabel(centralWidget);
        colorLabel->setObjectName(QStringLiteral("colorLabel"));
        colorLabel->setGeometry(QRect(1000, 280, 50, 50));
        colorLabel->setStyleSheet(QStringLiteral("border-color: rgb(238, 238, 236);"));
        sizeSlider = new QSlider(centralWidget);
        sizeSlider->setObjectName(QStringLiteral("sizeSlider"));
        sizeSlider->setGeometry(QRect(830, 390, 160, 21));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sizeSlider->sizePolicy().hasHeightForWidth());
        sizeSlider->setSizePolicy(sizePolicy);
        sizeSlider->setMaximum(3);
        sizeSlider->setSingleStep(0);
        sizeSlider->setPageStep(1);
        sizeSlider->setValue(3);
        sizeSlider->setOrientation(Qt::Horizontal);
        sizeSlider->setTickPosition(QSlider::TicksBelow);
        sizeSlider->setTickInterval(0);
        resolutionLabel = new QLabel(centralWidget);
        resolutionLabel->setObjectName(QStringLiteral("resolutionLabel"));
        resolutionLabel->setGeometry(QRect(860, 350, 111, 41));
        QFont font;
        font.setPointSize(14);
        resolutionLabel->setFont(font);
        resolutionLabel->setAlignment(Qt::AlignCenter);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setGeometry(QRect(10, 10, 768, 768));
        graphicsView->setFrameShadow(QFrame::Sunken);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        SpriteEditorWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SpriteEditorWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1080, 22));
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
        chooseColorBox->setText(QApplication::translate("SpriteEditorWindow", "Choose Color", nullptr));
        colorLabel->setText(QString());
        resolutionLabel->setText(QApplication::translate("SpriteEditorWindow", "Resolution", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpriteEditorWindow: public Ui_SpriteEditorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRITEEDITORWINDOW_H
