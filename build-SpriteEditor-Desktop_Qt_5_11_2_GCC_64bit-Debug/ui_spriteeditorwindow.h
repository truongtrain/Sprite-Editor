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
#include <QtWidgets/QListWidget>
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
    QListWidget *frameList;
    QPushButton *addFrameButton;
    QPushButton *removeFrameButton;
    QPushButton *duplicateButton;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SpriteEditorWindow)
    {
        if (SpriteEditorWindow->objectName().isEmpty())
            SpriteEditorWindow->setObjectName(QStringLiteral("SpriteEditorWindow"));
        SpriteEditorWindow->resize(1260, 1049);
        SpriteEditorWindow->setMinimumSize(QSize(300, 300));
        centralWidget = new QWidget(SpriteEditorWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        chooseColorBox = new QPushButton(centralWidget);
        chooseColorBox->setObjectName(QStringLiteral("chooseColorBox"));
        chooseColorBox->setGeometry(QRect(1040, 290, 151, 31));
        colorLabel = new QLabel(centralWidget);
        colorLabel->setObjectName(QStringLiteral("colorLabel"));
        colorLabel->setEnabled(true);
        colorLabel->setGeometry(QRect(1200, 280, 50, 50));
        colorLabel->setStyleSheet(QStringLiteral("border-color: rgb(238, 238, 236);"));
        colorLabel->setLineWidth(5);
        sizeSlider = new QSlider(centralWidget);
        sizeSlider->setObjectName(QStringLiteral("sizeSlider"));
        sizeSlider->setGeometry(QRect(1040, 390, 160, 21));
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
        resolutionLabel->setGeometry(QRect(1060, 350, 111, 41));
        QFont font;
        font.setPointSize(14);
        resolutionLabel->setFont(font);
        resolutionLabel->setAlignment(Qt::AlignCenter);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setGeometry(QRect(10, 10, 960, 960));
        graphicsView->setFrameShadow(QFrame::Sunken);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        frameList = new QListWidget(centralWidget);
        frameList->setObjectName(QStringLiteral("frameList"));
        frameList->setGeometry(QRect(990, 490, 251, 420));
        frameList->setDragDropOverwriteMode(true);
        frameList->setDragDropMode(QAbstractItemView::DragDrop);
        frameList->setDefaultDropAction(Qt::MoveAction);
        addFrameButton = new QPushButton(centralWidget);
        addFrameButton->setObjectName(QStringLiteral("addFrameButton"));
        addFrameButton->setGeometry(QRect(980, 920, 61, 31));
        removeFrameButton = new QPushButton(centralWidget);
        removeFrameButton->setObjectName(QStringLiteral("removeFrameButton"));
        removeFrameButton->setEnabled(true);
        removeFrameButton->setGeometry(QRect(1050, 920, 71, 31));
        duplicateButton = new QPushButton(centralWidget);
        duplicateButton->setObjectName(QStringLiteral("duplicateButton"));
        duplicateButton->setGeometry(QRect(1160, 920, 91, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(990, 450, 251, 31));
        QFont font1;
        font1.setPointSize(15);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        SpriteEditorWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SpriteEditorWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1260, 22));
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
        addFrameButton->setText(QApplication::translate("SpriteEditorWindow", "Add", nullptr));
        removeFrameButton->setText(QApplication::translate("SpriteEditorWindow", "Remove", nullptr));
        duplicateButton->setText(QApplication::translate("SpriteEditorWindow", "Duplicate", nullptr));
        label->setText(QApplication::translate("SpriteEditorWindow", "Frames", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpriteEditorWindow: public Ui_SpriteEditorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRITEEDITORWINDOW_H
