#include <stdio.h>
#include <gtk/gtk.h>

//Declare une zone de dessin
static GdkPixmap *pixmap = NULL;

//Initialize la zone de dessin, avec la taille qu'elle doit avoir ainsi que sa position
static gint
configure_event (GtkWidget *widget, GdkEventConfigure *event)
{
  if (pixmap)
    gdk_pixmap_unref(pixmap);

  pixmap = gdk_pixmap_new(widget->window,
                          widget->allocation.width,
                          widget->allocation.height,
                          -1);//Creer une fenetre avec la zone de dessins
  gdk_draw_rectangle (pixmap, //Alloue la taille et la position de la fenetre
                      widget->style->white_gc, //Fond blanc
                      TRUE,
                      0, 0,
                      widget->allocation.width, //Largeur
                      widget->allocation.height); //Heuteur

  return TRUE;
}

//Redessine la zone de dessin en fonction du tracer
static gint
expose_event (GtkWidget *widget, GdkEventExpose *event)
{
  //Permet de dessiner le tracer fait avec la souris
  gdk_draw_pixmap(widget->window,
                  widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
                  pixmap,
                  event->area.x, event->area.y, //Evenement 1 (x, y)
                  event->area.x, event->area.y, //Evenement 2 (x, y)
                  event->area.width, event->area.height); //Largeur et hauteur

  return FALSE;
}

//Dessine un rectangle sur la zone de dessin pour representer le tracer, 
//equivalent du pinceau dans un logiciel de dessin
static void
draw_brush (GtkWidget *widget, gdouble x, gdouble y)
{
  GdkRectangle update_rect; //Creer un rectangle

  update_rect.x = x - 5; //position x du rectangle
  update_rect.y = y - 5; //position y du rectangle
  update_rect.width = 10; //Largeur du rectangle
  update_rect.height = 10; //hauteur du rectangle
  //Dessine le rectangle 
  gdk_draw_rectangle (pixmap,
		      widget->style->black_gc,  //Rectangle de couleur nour
                      TRUE,
                      update_rect.x, update_rect.y,  
                      update_rect.width, update_rect.height);
  gtk_widget_draw (widget, &update_rect);
}

//Gere le clique de la sourir, si clique de la souris dessine un rectnagle
static gint
button_press_event (GtkWidget *widget, GdkEventButton *event)
{
  if (event->button == 1 && pixmap != NULL)
    draw_brush (widget, event->x, event->y);

  return TRUE;
}

static gint
motion_notify_event (GtkWidget *widget, GdkEventMotion *event)
{
  int x, y;
  GdkModifierType state;

  if (event->is_hint)
    gdk_window_get_pointer (event->window, &x, &y, &state);
  else
    {
      x = event->x;
      y = event->y;
      state = event->state;
    }
    
  if (state & GDK_BUTTON1_MASK && pixmap != NULL)
    draw_brush (widget, x, y);
  
  return TRUE;
}

void
quit ()
{
  gtk_exit (0); //Quitte l'aplication
}

int
main (int argc, char *argv[])
{
  GtkWidget *window;  //Declare une fentre GTK
  GtkWidget *drawing_area; //Declare une zone de dessi
  GtkWidget *vbox;  //Declare un une boite 

  GtkWidget *button; //Declarre un bouton

  gtk_init (&argc, &argv); //Initialise GTK

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL); //Creer uen fenetre GTK 
  gtk_widget_set_name (window, "Un petit programme GTK pour dessiner");

  vbox = gtk_vbox_new (FALSE, 0); //Crer une nouvelle boite
  gtk_container_add (GTK_CONTAINER (window), vbox); //Rajoute la boite a la fenetre
  gtk_widget_show (vbox);  //Affiche la boite

  gtk_signal_connect (GTK_OBJECT (window), "destroy",
                      GTK_SIGNAL_FUNC (quit), NULL);

  /* Create the drawing area */

  drawing_area = gtk_drawing_area_new (); //Crer une zone de dessins
  gtk_drawing_area_size (GTK_DRAWING_AREA (drawing_area), 200, 200); //Initialise la zone de dessins
  gtk_box_pack_start (GTK_BOX (vbox), drawing_area, TRUE, TRUE, 0); //Ajoute la zone de dessin a la boute

  gtk_widget_show (drawing_area); //Affiche la zone de dessin

  
  //Les differents signaux a connecteer
  gtk_signal_connect (GTK_OBJECT (drawing_area), "expose_event",
                      (GtkSignalFunc) expose_event, NULL);
  gtk_signal_connect (GTK_OBJECT(drawing_area),"configure_event",
                      (GtkSignalFunc) configure_event, NULL);

  gtk_signal_connect (GTK_OBJECT (drawing_area), "motion_notify_event",
                      (GtkSignalFunc) motion_notify_event, NULL);
  gtk_signal_connect (GTK_OBJECT (drawing_area), "button_press_event",
                      (GtkSignalFunc) button_press_event, NULL);

  gtk_widget_set_events (drawing_area, GDK_EXPOSURE_MASK
                         | GDK_LEAVE_NOTIFY_MASK
                         | GDK_BUTTON_PRESS_MASK
                         | GDK_POINTER_MOTION_MASK
                         | GDK_POINTER_MOTION_HINT_MASK);

  button = gtk_button_new_with_label ("Quitter"); //Creer un bouton avec le label Quitter
  gtk_box_pack_start (GTK_BOX (vbox), button, FALSE, FALSE, 0); //Initialise le bouton et l'ajoute a la boite

  //Ajoute le signal
  gtk_signal_connect_object (GTK_OBJECT (button), "clicked",
                             GTK_SIGNAL_FUNC (gtk_widget_destroy),
                             GTK_OBJECT (window));
  gtk_widget_show (button); //Affiche le bouton

  gtk_widget_show (window); //Affiche la fenetre

  gtk_main (); //Rend la main a l'application

  return 0;
}
