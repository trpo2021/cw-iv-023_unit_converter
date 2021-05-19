#include "lib_unit_converter/unit_converter.h"

void destroy_window(GtkWidget *window, gpointer data)
{
    (void)data;
    (void)window;
    gtk_main_quit();
}

void combobox_init(GtkWidget *combobox, category *arr_categors, int n_categors)
{
    int i;

    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combobox), "select category");
    for (i = 0; i < n_categors; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combobox), arr_categors[i].key);
    }
}