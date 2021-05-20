#include "lib_unit_converter/unit_converter.h"

int main(int argc, char** argv)
{
    GtkWidget *window, *box, *box_category, *box_convertion, *combobox_category, *combobox_from, *combobox_to;
    user_data *data_select_units_from, *data_select_units_to;
    FILE* file;
    file = fopen("src/unit_converter/data.txt", "r");
    if (file == NULL) {
        printf("ERROR cant open file\n");
        return 1;
    }
    int counter_line = line_counter(file);
    if (counter_line == 0) {
        printf("EROR file empty\n");
        return 1;
    }
    category* arr_categors = database_create(file, counter_line);
    fclose(file);
    if (argc == 2) {
        if (strcmp(argv[1], "--help") == 0) {
            help();
            while ((getchar()) != '\n')
                ;
        }
    }
    char input_str[SIZE_INPUT_STR] = {0};
    if (argc == 6) {
        if ((strcmp(argv[1], "--fast") == 0) || (strcmp(argv[1], "-f") == 0)) {
            build_str_fast(input_str, argc, argv);
        }
    } else {
        printf("You want: ");
        fgets(input_str, SIZE_INPUT_STR, stdin);
    }
    char* correct_str = NULL;
    int code_error = correct_input_str(input_str, &correct_str);
    if (code_error < 0) {
        print_errors(code_error);
        free_database(arr_categors, counter_line);
        return 1;
    }
    double converted_value = convert(correct_str, arr_categors, counter_line);
    if (converted_value < 0) {
        print_errors(converted_value);
        free_database(arr_categors, counter_line);
        return 1;
    }
    printf("Converted value = %lf\n", converted_value);
    free_database(arr_categors, counter_line);
    return 0;*/

    gtk_init(NULL, NULL);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    g_signal_connect (window, "destroy", G_CALLBACK (destroy_window), NULL);

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    box_category = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    box_convertion = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    gtk_box_pack_end(GTK_BOX(box), GTK_WIDGET(box_convertion), TRUE, TRUE, 5);
    gtk_box_pack_end(GTK_BOX(box), GTK_WIDGET(box_category), TRUE, TRUE, 5);

    combobox_category = gtk_combo_box_text_new();
    categories_init(combobox_category, arr_categors, counter_line);
    gtk_combo_box_set_active(GTK_COMBO_BOX(combobox_category), 0);
    gtk_box_pack_end(GTK_BOX(box_category), combobox_category, TRUE, TRUE, 5);

    combobox_from = gtk_combo_box_text_new();
    gtk_box_pack_end(GTK_BOX(box_convertion), combobox_from, TRUE, TRUE, 5);
    data_select_units_from->data_gtkwidget = combobox_from;
    data_select_units_from->categories_data =  arr_categors;
    g_signal_connect (combobox_category, "changed", G_CALLBACK(units_init), data_select_units_from);

    combobox_to = gtk_combo_box_text_new();
    data_select_units_to->data_gtkwidget = combobox_to;
    data_select_units_to->categories_data =  arr_categors;
    gtk_box_pack_end(GTK_BOX(box_convertion), combobox_to, TRUE, TRUE, 5);
    g_signal_connect (combobox_category, "changed", G_CALLBACK(units_init), data_select_units_to);

    gtk_container_add(GTK_CONTAINER(window), box);

    gtk_widget_show_all(window);

    gtk_main();
}
