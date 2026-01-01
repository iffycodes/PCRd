/*
  pcrd.h - Header file for Icom PCR-1000 control daemon

  Released under GPL. Please see the file LICENSE included with
  this source code.

  Author: Carl Walker (cwalker@icmp.com)
  Updated to v0.13 by Steven Haigh (http://www.crc.id.au/pcrd)
*/

#ifndef PCRD_H
#define PCRD_H

/* Standard includes */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

/* Socket support */
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

/* Constants */
#define _ASSIGNED_PORT_ 5151

/* Structure definitions */

/* Alarm signal function structure */
struct alarm_signal {
  int enabled;
  int expired;
  int exit_on_alarm;
  int time;
};

/* Radio reporting structure */
struct radio_report {
  char squ[8];
  char sig[8];
  char foffset[8];
  char pwr[8];
  int  ok;
  int  ng;
  int count;
  char input_buffer[256];
  int report_enable;
  double last_freq;
  int last_mode;
  int last_filter;
};

/* Radio command structure */
struct radio_command {
  char volcmd[8];
  char squcmd[8];
  char agccmd[8];
  char if_shiftcmd[8];
  char attncmd[8];
  char nbcmd[8];
  char off_cmd[8];
  char freq_command[32];
};

/* Command line option structure */
struct command_line {
  int init_radio, init_volume, init_squelch;
  int init_if_shift, init_attn, init_agc, init_nb;
  int default_mode, default_filter;
  int opt_d;
  int opt_off;
  int loop;
  int convert;
  int debug_level;
  char port[32];
  char default_port[32];
  char filter[16], mode[16];
  char volume[16];
  char squelch[16];
  char if_shift[16];
  int assigned_port;
  char raw_mode[16];
  char raw_filter[16];
  int init_done;
  double freq;
  char freq_command[32];
  char freq_command_output[32];
  int daemon;
};

/* Global variable declarations */
extern char not_normal_char[8];
extern char sig_query[8];
extern char pwr_query[8];
extern char pwron_cmd[8];
extern char squ_query[8];
extern char foffset_query[8];
extern char ok_reply[8];
extern char ng_reply[8];
extern char *program_name;
extern float version;
extern void *notso_local_pointer;
extern pid_t daemon_pid;
extern time_t start_time;
extern time_t current_time;
extern time_t elapsed_time;

/* Global structure instances */
extern struct alarm_signal as;
extern struct radio_report rpt;
extern struct radio_command cmd;
extern struct command_line cmd_line;

/* Global socket variables */
extern struct sockaddr_in socket_addr;
extern int conn;
extern int sock;
extern int conn_socket;
extern int serial_fd;

/* Function prototypes */

/* Alarm signal handling */
int alarm_set(unsigned int seconds, int enabled);
void alarm_disable(void);
void alarm_exit_enable(void);
void alarm_exit_disable(void);
void alarm_handler(void);

/* Utility functions */
void usage(void);
void clean_up(void);
void write_check(int len_sent, int len_string);

/* Command generation and parsing */
void generate_command_set(char *argv[], int fd, int sock_mode);
void parse_command_line(int argc, char **argv, int sock_mode);
int figure_mode(char *raw_mode, char *mode, int default_mode, int opt_off, int sock_mode);
int figure_filter(char *raw_filter, char *filter, int default_filter, int opt_off, int sock_mode);
int figure_freq(char *freq_command, char *freq_command_output, double freq);

/* Radio communication */
int send_command_get_reply(int fd, char *sig_query, char *input_buffer);
int get_radio_reply(char *input_buffer, int fd);
void decipher_radio_reply(char *input_buffer, int len);
int match_and_update(char *input_buffer, char *match_string, int length, 
                    char *output_location, int term);

/* Serial port handling */
void set_serial(int fd, struct termios *options, struct termios *way_it_was);
void restore_serial(int fd, struct termios *way_it_was);
int open_port(char *port_name);
void close_port(int fd);
int init(int fd, int init_done, char *input_buffer);

/* Reporting functions */
void report_reply_data(void);
void report_reply_data_socket(int socket);

/* Socket handling */
int check_socket(int sock, char* greeting, char *prompt);
int close_socket(int sock);

#endif /* PCRD_H */
