#include<gtk/gtk.h>

GdkPixbuf *create_pixbuf(const gchar * filename)
{
	GdkPixbuf *pixbuf;
	GError *error=NULL;
	pixbuf=gdk_pixbuf_new_from_file(filename,&error);
	if(!pixbuf){
	fprintf(stderr,"%s\n", error->message);
	g_error_free(error);
	}
}
void print_msg(GtkWidget *Widget, gpointer window){
	g_printf("button clicked\n");
}
int main(int argc, char*argv[])
{
	gtk_init(&argc,&argv);//initialization of GTk
	GtkWidget *window,*label,*button, *halign;//declaring variables
	GdkPixbuf *icon;
	window= gtk_window_new(GTK_WINDOW_TOPLEVEL);//create the window
	label= gtk_label_new("Hello world");
	button=gtk_button_new_with_mnemonic("_Hello world");
	g_signal_connect(button,"clicked",G_CALLBACK(print_msg),NULL);
	gtk_widget_set_tooltip_text(button,"Button Widget");
	halign=gtk_alignment_new(0,0,0,0);
	g_signal_connect(window, "delete_event",G_CALLBACK(gtk_main_quit),NULL);//if 'X' was clicked then exit from the program
	gtk_container_add(GTK_CONTAINER(halign),button);//button on window
	gtk_container_add(GTK_CONTAINER(window),halign);
	gtk_window_set_title(GTK_WINDOW(window),"hello");//setting title of window to hello
	gtk_window_set_default_size(GTK_WINDOW(window),300,300);
	gtk_container_set_border_width(GTK_CONTAINER(button),10);
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	icon=create_pixbuf("/home/panther2/Pictures/world.jpeg");
	gtk_window_set_icon(GTK_WINDOW(window),icon);
	gtk_widget_show_all(window);//we show all widgets
	g_object_unref(icon);
	gtk_main();//start the main loop
	return 0;
}
