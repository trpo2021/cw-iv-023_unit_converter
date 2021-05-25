#include "lib_unit_converter/unit_converter.h"

    static GtkWidget *combobox_category, *combobox_from, *combobox_to;
    static GtkWidget *entry;
    static GtkWidget *label;
    static GtkWidget *button;

void destroy_window(GtkWidget* window, gpointer data)
{
    (void)data;
    (void)window;
    gtk_main_quit();
}

void categories_init(category* arr_categories, int categories_n)
{
    int i;
    
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combobox_category),"select category");
    for (i = 0; i < categories_n; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combobox_category), arr_categories[i].key);
    }
}

void units_select(GtkWidget *combobox_category, category *arr_categories)
{
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(combobox_from));
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(combobox_to));
    
    int i, active_category;

    active_category = gtk_combo_box_get_active(GTK_COMBO_BOX(combobox_category));

    if (active_category != 0){
        
        for (i = 0; i < arr_categories[active_category - 1].units_counter; i++){
            gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combobox_from), arr_categories[active_category - 1].units[i].key);
        }
        gtk_combo_box_set_active(GTK_COMBO_BOX(combobox_from), 0);

        
        for (i = 0; i < arr_categories[active_category - 1].units_counter; i++){
            gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combobox_to), arr_categories[active_category - 1].units[i].key);
        }
        gtk_combo_box_set_active(GTK_COMBO_BOX(combobox_to), 0);
    }
}

/*void combobox_category_get_active(GtkWidget *button, GtkWidget *combobox_category)
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

void get_all_values()
{
    g_signal_connect (button, "clicked", G_CALLBACK(combobox_category_get_active), combobox_category);
    g_signal_connect (button, "clicked", G_CALLBACK(combobox_unit_from_get_active), combobox_from);
    g_signal_connect (button, "clicked", G_CALLBACK(combobox_unit_to_get_active), combobox_to);
    g_signal_connect (button, "clicked", G_CALLBACK(entry_get_value), entry);
}

void do_convert(category *arr_categories)
{
    result = (value * (arr_categories[category_number].units[unit_to_number].value /
        arr_categories[category_number].units[unit_from_number].value));
}*/

void start_graphic(category *arr_categories, int categories_n)
{
    gtk_init(NULL, NULL);

    GtkWidget *window;
    GtkWidget *box, *box_category, *box_convertion, *box_result;

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
    categories_init(arr_categories, categories_n);
    gtk_combo_box_set_active(GTK_COMBO_BOX(combobox_category), 0);
    gtk_box_pack_end(GTK_BOX(box_category), combobox_category, TRUE, TRUE, 5);

    combobox_from = gtk_combo_box_text_new();
    combobox_to = gtk_combo_box_text_new();
    g_signal_connect(combobox_category, "changed", G_CALLBACK(units_select), arr_categories);
    gtk_box_pack_end(GTK_BOX(box_convertion), combobox_from, TRUE, TRUE, 5);
    gtk_box_pack_end(GTK_BOX(box_convertion), combobox_to, TRUE, TRUE, 5);

    //get_all_values(button, combobox_category, combobox_from, combobox_to, entry);
    //g_signal_connect(button, "clicked", G_CALLBACK(calculate), arr_categories);



    gtk_container_add(GTK_CONTAINER(window), box);

    gtk_widget_show_all(window);

    gtk_main();
}