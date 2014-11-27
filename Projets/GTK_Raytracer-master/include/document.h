/*
** document.h for raytracer in /home/raine_v/Projets/C/Tek1/test/gtk/editeur/includes
**
** Made by Vincent Raine
** Login   <raine_v@epitech.net>
**
** Started on  Thu Jun  5 14:06:14 2014 Vincent Raine
// Last update Thu Jun  5 14:07:39 2014 Vincent Raine
*/

#ifndef		__DOCUMENT_H__
# define	__DOCUMENT_H__

# include	<gtk/gtk.h>

typedef struct
{
  gchar	*path;
  gboolean	sauve;
  GtkTextView	*text_view;
} document_t;

typedef struct
{
  GList	*tous;
  document_t	*actif;
  GtkWindow	*main_window;
} docs_t;

extern docs_t	docs;

# endif /* __DOCUMENT_H__ */
