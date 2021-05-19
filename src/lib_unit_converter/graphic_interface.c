#include "lib_unit_converter/unit_converter.h"

void destroy_window(GtkWidget *window, gpointer data)
{
    (void)data;
    (void)window;
    gtk_main_quit();
}

