#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define _command struct Command

_command {
  char name[20];
  _command *subcommands;
  int subcommand_count;
  int verbose;
  char *subcommand;
  char **args;
  int arg_count;
};

_command create_root_command();
void add_subcommand(_command *command, const char *name, _command subcommand);
void add_argument(_command *command, const char *short_option,
                  const char *long_option, int arg_required);
void parse_args(_command *command, int argc, char *argv[]);
void print_command(_command *command);

int main(int argc, char *argv[]) {
  _command root = create_root_command();

  _command cmd1 = create_root_command();
  _command cmd1_foo = create_root_command();
  add_argument(&cmd1_foo, "-n", "--name", 1);
  add_subcommand(&cmd1, "foo", cmd1_foo);
  add_subcommand(&root, "cmd1", cmd1);

  _command cmd2 = create_root_command();
  _command cmd2_bar = create_root_command();
  add_argument(&cmd2_bar, "-s", "--size", 1);
  add_subcommand(&cmd2, "bar", cmd2_bar);
  add_subcommand(&root, "cmd2", cmd2);

  parse_args(&root, argc, argv);

  print_command(&root);

  return 0;
}

_command create_root_command() {
  _command command;
  strncpy(command.name, "", sizeof(command.name));
  command.subcommands = NULL;
  command.subcommand_count = 0;
  command.verbose = 0;
  command.subcommand = NULL;
  command.args = NULL;
  command.arg_count = 0;
  return command;
}

void add_subcommand(_command *command, const char *name, _command subcommand) {
  command->subcommands = realloc(
      command->subcommands, (command->subcommand_count + 1) * sizeof(_command));
  command->subcommands[command->subcommand_count++] = subcommand;
}

void add_argument(_command *command, const char *short_option,
                  const char *long_option, int arg_required) {
  int option_index = command->arg_count;
  command->args =
      realloc(command->args, (command->arg_count + 1) * sizeof(char *));
  command->args[option_index] = malloc(strlen(short_option) + 1);
  strcpy(command->args[option_index], short_option);
  command->arg_count++;

  option_index = command->arg_count;
  command->args =
      realloc(command->args, (command->arg_count + 1) * sizeof(char *));
  command->args[option_index] = malloc(strlen(long_option) + 1);
  strcpy(command->args[option_index], long_option);
  command->arg_count++;
}

void parse_args(_command *command, int argc, char *argv[]) {
  int option;
  int option_index = 0;
  struct option long_options[] = {{"verbose", no_argument, NULL, 'v'},
                                  {NULL, 0, NULL, 0}};

  while ((option = getopt_long(argc, argv, "v", long_options, &option_index)) !=
         -1) {
    switch (option) {
    case 'v':
      command->verbose++;
      break;
    default:
      break;
    }
  }

  if (optind < argc) {
    command->subcommand = argv[optind++];
    command->args = &argv[optind];
    command->arg_count = argc - optind;
  }
}

void print_command(_command *command) {
  printf("Command name: %s\n", command->name);
  printf("Verbose level: %d\n", command->verbose);
  printf("Subcommand: %s\n", command->subcommand);

  printf("Arguments:\n");
  for (int i = 0; i < command->arg_count; i++) {
    printf("- %s\n", command->args[i]);
  }

  printf("Subcommands:\n");
  for (int i = 0; i < command->subcommand_count; i++) {
    print_command(&command->subcommands[i]);
  }
}
