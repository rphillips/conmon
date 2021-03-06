#if !defined(CTR_EXIT_H)
#define CTR_EXIT_H

#include <sys/types.h> /* pid_t */
#include <glib.h>      /* gpointer, gboolean, GHashTable, and GPid */


extern volatile pid_t container_pid;
volatile pid_t create_pid;

void on_sigchld(G_GNUC_UNUSED int signal);
void on_sig_exit(int signal);
void container_exit_cb(G_GNUC_UNUSED GPid pid, int status, G_GNUC_UNUSED gpointer user_data);
void check_child_processes(GHashTable *pid_to_handler);
gboolean on_sigusr1_cb(gpointer user_data);
gboolean timeout_cb(G_GNUC_UNUSED gpointer user_data);
int get_exit_status(int status);
void runtime_exit_cb(G_GNUC_UNUSED GPid pid, int status, G_GNUC_UNUSED gpointer user_data);
void container_exit_cb(G_GNUC_UNUSED GPid pid, int status, G_GNUC_UNUSED gpointer user_data);
void do_exit_command();

#endif // CTR_EXIT_H
