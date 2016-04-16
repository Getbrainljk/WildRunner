/*
** msdl_macro.h for minisdl_cpp in /home/le-mai_s/librairie/minisdl_cpp/include
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Sun Nov  8 16:35:39 2015 sebastien le-maire
** Last update Wed Jan 27 15:12:42 2016 Sébastien Le Maire
*/

#ifndef MSDL_MACRO_HPP_
# define MSDL_MACRO_HPP_

/*
** Initialisation
*/
# define ALL_OFF				(0)
# define RESIZE_ON				(1)
# define TIMER_ON				(2)
# define RESIZE_TIMER_ON			(3)
# define FULLSCREEN_ON				(4)
# define TIMER_FULLSCREEN_ON			(6)
# define AUDIO_ON				(8)
# define RESIZE_AUDIO_ON			(9)
# define TIMER_AUDIO_ON				(10)
# define RESIZE_TIMER_AUDIO_ON			(11)
# define FULLSCREEN_AUDIO_ON			(12)
# define TIMER_FULLSCREEN_AUDIO_ON		(14)
# define OPENGL_ON				(16)
# define RESIZE_OPENGL_ON			(17)
# define TIMER_OPENGL_ON			(18)
# define RESIZE_TIMER_OPENGL_ON			(19)
# define FULLSCREEN_OPENGL_ON			(20)
# define TIMER_FULLSCREEN_OPENGL_ON		(22)
# define AUDIO_OPENGL_ON			(24)
# define RESIZE_AUDIO_OPENGL_ON			(25)
# define TIMER_AUDIO_OPENGL_ON			(26)
# define RESIZE_TIMER_AUDIO_OPENGL_ON		(27)
# define FULLSCREEN_AUDIO_OPENGL_ON		(28)
# define TIMER_FULLSCREEN_AUDIO_OPENGL_ON	(30)

/*
** State of events
*/
# define MSDL_KEYPRESS		(1)
# define MSDL_KEYRELEASE       	(2)
# define MSDL_KEY_EVENT		(3)
# define MSDL_MOUSEPRESS	(4)
# define MSDL_MOUSERELEASE	(8)
# define MSDL_MOUSEBUTTON_EVENT	(12)
# define MSDL_MOUSEMOTION	(16)
# define MSDL_MOUSE_EVENT	(28)
# define MSDL_ALL_EVENT		(31)

/*
** Use in msdl_audio_init. You can use MIX_DEFAULT_FREQUENCY
*/
# define CD_QUALITY	(44100)

/*
** Use in msdl_play_music and msdl_play_sound.
*/
# define AUDIO_LOOP_INF	(-1)

/*
** Color A R G B |||| B G R A
*/
# define RGB_LIT_END(r, g, b) (((r) << 16) | ((g) << 8) | (b))
# define RGB_BIG_END(r, g, b) (((r) >> 16) | ((g) >> 8) | (b))

/*
** Permit to give event to left shift + every key on the keyboard.
*/
# define COND_SIMULT_KEY_LSHIFT ((mode & KMOD_LSHIFT) == KMOD_LSHIFT)

/*
** Other
*/
# define MSDL_ABS(nb)		(((nb) > 0) ? (nb) : (-(nb)))
# define MSDL_INT_TO_CHAR(i)	((i) + '0')

#endif /* !MSDL_MACRO_HPP_ */
