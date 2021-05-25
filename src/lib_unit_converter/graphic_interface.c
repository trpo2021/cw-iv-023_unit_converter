#include "lib_unit_converter/unit_converter.h"

int unit_from_number = -1, unit_to_number = -1, category_number;
double value = 0;

void destroy_window(GtkWidget* window, gpointer data)
{
    (void)data;
    (void)window;
    gtk_main_quit();
}

void categories_init(GtkWidget* combobox, category* arr_categories, int categories_n)
{
    int i;
    
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combobox),"select category");
    for (i = 0; i < categories_n; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combobox), arr_categories[i].key);
    }
}

void units_select(GtkWidget* combobox_category, data *unit_data)
{
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(unit_data->widget));

    int i, active_category;

    active_category = gtk_combo_box_get_active(GTK_COMBO_BOX(combobox_category));

    switch (active_category) {
        case 1:
            for (i = 0; i < unit_data->arr_categories[active_category - 1].units_counter; i++){
                gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(unit_data->widget), unit_data->arr_categories[active_category - 1].units[i].key);
            }
            break;
        case 2:
            for (i = 0; i < unit_data->arr_categories[active_category - 1].units_counter; i++){
                gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(unit_data->widget), unit_data->arr_categories[active_category - 1].units[i].key);
            }
            break;
        case 3:
            for (i = 0; i < unit_data->arr_categories[active_category - 1].units_counter; i++){
                gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(unit_data->widget), unit_data->arr_categories[active_category - 1].units[i].key);
            }
            break;
        case 4:
            for (i = 0; i < unit_data->arr_categories[active_category - 1].units_counter; i++){
                gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(unit_data->widget), unit_data->arr_categories[active_category - 1].units[i].key);
            }
            break;
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(unit_data->widget), 0);
}

void combobox_category_get_active(GtkWidget *button, GtkWidget *combobox_category)
{
    (void)button;
    category_number = gtk_combo_box_get_active(GTK_COMBO_BOX(combobox_category)) - 1;
}

void combobox_unit_from_get_active(GtkWidget *button, GtkWidget *combobox_from)
{
    (void)button;
    unit_from_number = gtk_combo_box_get_active(GTK_COMBO_BOX(combobox_from));
}

void combobox_unit_to_get_active(GtkWidget *button, GtkWidget *combobox_to)
{
    (void)button;
    unit_to_number = gtk_combo_box_get_active(GTK_COMBO_BOX(combobox_to));
}

void entry_get_value(GtkWidget *button, GtkWidget *entry)
{
    (void)button;
    value = atof(gtk_entry_get_text(GTK_ENTRY(entry)));
}

void get_all_values(GtkWidget *button, GtkWidget *combobox_category, GtkWidget *combobox_from, GtkWidget *combobox_to, GtkWidget *entry)
{
    g_signal_connect (button, "clicked", G_CALLBACK(combobox_category_get_active), combobox_category);
    g_signal_connect (button, "clicked", G_CALLBACK(combobox_unit_from_get_active), combobox_from);
    g_signal_connect (button, "clicked", G_CALLBACK(combobox_unit_to_get_active), combobox_to);
    g_signal_connect (button, "clicked", G_CALLBACK(entry_get_value), entry);
}


void start_graphic(category *arr_categories, int categories_n)
{
    gtk_init(NULL, NULL);

    GtkWidget *window;
    GtkWidget *box, *box_category, *box_convertion, *box_result;
    GtkWidget *combobox_category,*combobox_from, *combobox_to;
    GtkWidget *entry;
    GtkWidget *label;
    GtkWidget *button;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    g_signal_connect (window, "destroy", G_CALLBACK (destroy_window), NULL);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    box_category = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    box_convertion = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    box_result = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_end(GTK_BOX(box), GTK_WIDGET(box_result), TRUE, TRUE, 5);
    gtk_box_pack_end(GTK_BOX(box), GTK_WIDGET(box_convertion), TRUE, TRUE, 5);
    gtk_box_pack_end(GTK_BOX(box), GTK_WIDGET(box_category), TRUE, TRUE, 5);

    entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box_convertion), entry, TRUE, TRUE, 5);

    button = gtk_button_new_with_label("convert!!!");
    gtk_box_pack_end(GTK_BOX(box_convertion), button, TRUE, TRUE, 5);

    label = gtk_label_new("result");
    gtk_box_pack_end(GTK_BOX(box_result), label, TRUE, TRUE, 5);

    combobox_category = gtk_combo_box_text_new();
    categories_init(combobox_category, arr_categories, categories_n);
    gtk_combo_box_set_active(GTK_COMBO_BOX(combobox_category), 0);
    gtk_box_pack_end(GTK_BOX(box_category), combobox_category, TRUE, TRUE, 5);

    data *unit_from_data = malloc(sizeof(*unit_from_data));
    combobox_from = gtk_combo_box_text_new();
    unit_from_data->arr_categories = arr_categories;
    unit_from_data->widget = combobox_from;
    g_signal_connect(combobox_category, "changed", G_CALLBACK(units_select), unit_from_data);
    gtk_box_pack_end(GTK_BOX(box_convertion), combobox_from, TRUE, TRUE, 5);
    
    data *unit_to_data = malloc(sizeof(*unit_to_data));
    combobox_to = gtk_combo_box_text_new();
    unit_to_data->arr_categories = arr_categories;
    unit_to_data->widget = combobox_to;
    g_signal_connect(combobox_category, "changed", G_CALLBACK(units_select), unit_to_data);
    gtk_box_pack_end(GTK_BOX(box_convertion), combobox_to, TRUE, TRUE, 5);

    gtk_container_add(GTK_CONTAINER(window), box);

    gtk_widget_show_all(window);

    gtk_main();

    free(unit_from_data);
    free(unit_to_data);
}