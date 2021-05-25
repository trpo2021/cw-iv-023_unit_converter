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

void combobox_category_get_active(GtkWidget *button, gpointer active_category)
{
    (void)button;
    *((int*)active_category) = gtk_combo_box_get_active(GTK_COMBO_BOX(combobox_category)) - 1;
    g_print("%d\n", *((int*)active_category));
}

void combobox_unit_from_get_active(GtkWidget *button, gpointer active_unit_from)
{
    (void)button;
    *((int*)active_unit_from) = gtk_combo_box_get_active(GTK_COMBO_BOX(combobox_from));
    g_print("%d\n", *((int*)active_unit_from));
}

void combobox_unit_to_get_active(GtkWidget *button, gpointer active_unit_to)
{
    (void)button;
    *((int*)active_unit_to) = gtk_combo_box_get_active(GTK_COMBO_BOX(combobox_to));
    g_print("%d\n", *((int*)active_unit_to));
}

void entry_get_value(GtkWidget *button, gpointer value)
{
    (void)button;
    *(double *)value = atof(gtk_entry_get_text(GTK_ENTRY(entry)));
    g_print("%lf\n", *(double *)value);
}

double do_convert(category *arr_categories, int active_category, int active_unit_from, int active_unit_to, double value)
{
    return (value * (arr_categories[active_category].units[active_unit_to].value /
        arr_categories[active_category].units[active_unit_from].value));
}

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

    gtk_container_add(GTK_CONTAINER(window), box);

    gtk_widget_show_all(window);

    gtk_main();
}