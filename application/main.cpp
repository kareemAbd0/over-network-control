#include <iostream>
#include "app/app.h"

int main() {



    App& app = App::get_instance();
    app.init();
    app.run();

    return 0;
}
