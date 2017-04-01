#include "Application.h"
#include "ImageView.h"

extern ImageView *gImageView;

int main(int argc, char **argv) {
  Application app(argc, argv);
  return app.run();
}
