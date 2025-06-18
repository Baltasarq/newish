// (c) 2024 newiSH Baltasar MIT License <baltasarq@gmail.com>


/** Converts the usr file name (a file name with spaces),
  * into a sys file name (a name with underscores).
  * @param usr_file_name the file name from the user's view.
  * @return a pointer to the given file name, with spaces converted to underscores.
  */
char *sys_file_name_from_usr_file_name(char *usr_file_name);


/** Converts the sys file name (a file name with underscores),
  * into a usr file name (a name with spaces).
  * @param sys_file_name the file name from the system's view.
  * @return a pointer to the given file name, with underscores converted to spaces.
  */
char *usr_file_name_from_sys_file_name(char *sys_file_name);
