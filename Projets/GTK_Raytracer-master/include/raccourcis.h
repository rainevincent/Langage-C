/*
** raccourcis.h for raytracer in /home/raine_v/Projets/C/Tek1/test/gtk/editeur/includes
**
** Made by Vincent Raine
** Login   <raine_v@epitech.net>
**
** Started on  Thu Jun  5 14:10:13 2014 Vincent Raine
// Last update Thu Jun  5 14:11:57 2014 Vincent Raine
*/

#ifndef		__RACCOURCIS_H__
# define	__RACCOURCIS_H__

# include	<glib.h>

# define	ACCEL_PATH_NEW "<EditeurGTK>/Fichier/Nouveau"
# define	ACCEL_PATH_OPEN "<EditeurGTK>/Fichier/Ouvrir"
# define	ACCEL_PATH_SAVE "<EditeurGTK>/Fichier/Enregistrer"
# define	ACCEL_PATH_SAVEAS "<EditeurGTK>/Fichier/Enregistrer sous"
# define	ACCEL_PATH_CLOSE "<EditeurGTK>/Fichier/Fermer"
# define	ACCEL_PATH_QUIT "<EditeurGTK>/Fichier/Quitter"

GtkAccelGroup	*accel_group_new (gpointer);

# endif		/* __RACCOURCIS_H__ */
