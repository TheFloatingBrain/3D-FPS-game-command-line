#ifndef FPS_3D_COMMAND_LINE_KEYBOARD_HEADER_H
#define FPS_3D_COMMAND_LINE_KEYBOARD_HEADER_H

#if defined(_WIN32) || defined(__CYGWIN__)
	#include <winuser.h>
        char ReadKey(char key_number){
                //TODO: Consider using GetAsyncKeyState
                return GetKeyState(key_number) & 0x8000;
        }
#else

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Most of this shamelessly yoinked from https://stackoverflow.com/questions/448944/c-non-blocking-keyboard-input //
        // In seriousness, thank you (user) Alnitak ////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        #include <unistd.h>
        #include <sys/select.h>
        #include <termios.h>

        struct termios orig_termios;

        void reset_terminal_mode(){
                tcsetattr(0, TCSANOW, &orig_termios);
        }

        void set_conio_terminal_mode(){
            struct termios new_termios;

            /* take two copies - one for now, one for later */
            tcgetattr(0, &orig_termios);
            memcpy(&new_termios, &orig_termios, sizeof(new_termios));

            /* register cleanup handler, and set the new terminal mode */
            atexit(reset_terminal_mode);
            cfmakeraw(&new_termios);
            tcsetattr(0, TCSANOW, &new_termios);
        }

        int kbhit(){
            struct timeval tv = { 0L, 0L };
            fd_set fds;
            FD_ZERO(&fds);
            FD_SET(0, &fds);
            return select(1, &fds, NULL, NULL, &tv) > 0;
        }

        int getch(){
            int r;
            unsigned char c;
            if ((r = read(0, &c, sizeof(c))) < 0) {
                return r;
            } else {
                return c;
            }
        }

        char ReadKey(char key){
                return kbhit() ? (getch()==key) : 0;
        }

#endif

#endif // FPS_3D_COMMAND_LINE_KEYBOARD_HEADER_H

