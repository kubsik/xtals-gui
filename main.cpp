#include "toolbox.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ToolBox *window = new ToolBox;
    window->show();

    return app.exec();
}
