#include<gtk/gtk.h>


int main(int argc, char*argv[])
{
	gtk_init(&argc,&argv);//initialization of GTk
	GtkWidget *window,*label,*button;//declaring variables
	window= gtk_window_new(GTK_WINDOW_TOPLEVEL);//create the window
	label= gtk_label_new("Hello world");
	button=gtk_button_new();
	g_signal_connect(window, "delete_event",G_CALLBACK(gtk_main_quit),NULL);//if 'X' was clicked then exit from the program 
	gtk_container_add(GTK_CONTAINER(button),label);//label on button
	gtk_container_add(GTK_CONTAINER(window),button);//button on window
	gtk_window_set_title(GTK_WINDOW(window),"hello");//setting title of window to hello
	gtk_container_set_border_width(GTK_CONTAINER(button),10);
	gtk_widget_show_all(window);//we show all widgets
	gtk_main();//start the main loop
	return 0;
}
