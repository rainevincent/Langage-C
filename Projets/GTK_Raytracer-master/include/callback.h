/*
** callback.h for raytracer in /home/raine_v/Projets/C/Tek1/test/gtk/editeur
**
** Made by Vincent Raine
** Login   <raine_v@epitech.net>
**
** Started on  Thu Jun  5 14:04:39 2014 Vincent Raine
// Last update Thu Jun  5 14:05:56 2014 Vincent Raine
*/

#ifndef		__CALLBACK_H__
# define	__CALLBACK_H__

# include	<gtk/gtk.h>

void	cb_new (GtkWidget *, gpointer);
void	cb_open (GtkWidget *, gpointer);
void	cb_save (GtkWidget *, gpointer);
void	cb_saveas (GtkWidget *, gpointer);
void	cb_close (GtkWidget *, gpointer);
void	cb_quit (GtkWidget *, gpointer);
void	cb_modifie (GtkWidget *, gpointer);

# endif /* __CALLBACK_H__ */
