#include "RotationMenu.h"

#include "ImageView.h"

extern ImageView *gImageView;

RotationMenu::RotationMenu() {
  setup();
}

RotationMenu::~RotationMenu() {
}

void RotationMenu::reload() {
}

void RotationMenu::setup() {
  setTitle("Rotation");

  addRotateLeftAction();
  addRotateRightAction();
}

void RotationMenu::addRotateLeftAction() {
  mRotateLeftAction = new QAction();
  mRotateLeftAction->setText("Rotate Left");

  connect(mRotateLeftAction,
          &QAction::triggered,
          this,
          &RotationMenu::rotateLeft);

  addAction(mRotateLeftAction);
}

void RotationMenu::addRotateRightAction() {
  mRotateRightAction = new QAction();
  mRotateRightAction->setText("Rotate Right");

  connect(mRotateRightAction,
          &QAction::triggered,
          this,
          &RotationMenu::rotateRight);

  addAction(mRotateRightAction);
}

void RotationMenu::rotateLeft() {
  gImageView->rotateLeft();
}

void RotationMenu::rotateRight() {
  gImageView->rotateRight();
}
