#include "lib_unit_converter/unit_converter.h"

void destroy_window(GtkWidget* window, gpointer data)
{
    (void)data;
    (void)window;
    gtk_main_quit();
}

void categories_init(GtkWidget* combobox, category* arr_categors, int n)
{
    int i;
    
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combobox),"select category");
    for (i = 0; i < n; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combobox), arr_categors[i].key);
    }
}

void units_init(GtkWidget* combobox_category, user_data *data)
{
        gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(data->data_gtkwidget));

    int active_category;
    int i;

    active_category = gtk_combo_box_get_active(GTK_COMBO_BOX(combobox_category));

    switch (active_category) {
        case 1:
            for (i = 0; i < data->categories_data[active_category - 1].units_counter; i++){
                gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(data->data_gtkwidget), data->categories_data[active_category - 1].units[i].key);
            }
            gtk_combo_box_set_active(GTK_COMBO_BOX(data->data_gtkwidget), 0);
            break;
        case 2:
            for (i = 0; i < data->categories_data[active_category - 1].units_counter; i++){
                gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(data->data_gtkwidget), data->categories_data[active_category - 1].units[i].key);
            }
            gtk_combo_box_set_active(GTK_COMBO_BOX(data->data_gtkwidget), 0);
            break;
        case 3:
            for (i = 0; i < data->categories_data[active_category - 1].units_counter; i++){
                gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(data->data_gtkwidget), data->categories_data[active_category - 1].units[i].key);
            }
            gtk_combo_box_set_active(GTK_COMBO_BOX(data->data_gtkwidget), 0);
            break;
        case 4:
            for (i = 0; i < data->categories_data[active_category - 1].units_counter; i++){
                gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(data->data_gtkwidget), data->categories_data[active_category - 1].units[i].key);
            }
            gtk_combo_box_set_active(GTK_COMBO_BOX(data->data_gtkwidget), 0);
            break;
    }
}