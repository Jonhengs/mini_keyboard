
#ifndef _MAIN_H_
#define _MAIN_H_

/*! \brief Called by HID interface
 * Callback running when USB Host enable keyboard interface
 *
 * \retval true if keyboard startup is ok
 */
bool main_kbd_enable(void);

/*! \brief Called by HID interface
 * Callback running when USB Host disable keyboard interface
 */
void main_kbd_disable(void);

#endif // _MAIN_H_
