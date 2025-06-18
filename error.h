// (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>


#ifndef ERROR_H
#define ERROR_H


typedef enum _panic {
    PANIC_NOT_ENOUGH_MEMORY = -100,
} Panic;


typedef enum _error_level {
    Info,
    Debug,
    Warning,
    Error,
} ErrorLevel;


/** Strings equivalent to each error level. */
extern const char * StrErrorLevel[];

/** Stops app with a given error. It never returns.
  * @param panic the motivation of the panic state.
  * @param msg_error the error message.
  */
void panic(Panic panic, const char * msg_error);

/** Formats an error with the corresponding prefix.
  * @param level the error level.
  * @param msg_error the error message to be prepended.
  * @return a pointer to an internal buffer.
  */
const char * fmt_error(ErrorLevel level, const char* msg_error);

/** Formats a message after an error, an explanation in the next line.
  * @param msg_error the explanation message to be prepended with enough spaces.
  * @return a pointer to an internal buffer.
  */
const char * fmt_explanation(const char* msg_error);


#endif
