import argparse
import copy


class Command:
    def __init__(self):
        self.subcommands = {}
        self.parser = argparse.ArgumentParser()

    def add_subcommand(self, name, sub):
        self.subcommands[name] = sub

    def add_argument(self, *args, **kwargs):
        return self.parser.add_argument(*args, **kwargs)

    def parse_args(self, args=None):
        if not self.subcommands:
            args = self.parser.parse_args(args)
            return args

        p = copy.deepcopy(self.parser)
        p.add_argument("subcommand")
        p.add_argument("args", nargs=argparse.REMAINDER)
        args = p.parse_args(args)

        try:
            sub = self.subcommands[args.subcommand]
        except KeyError:
            return self.parser.parse_args(args)

        sub_args = sub.parse_args(args.args)

        for attr in dir(sub_args):
            if attr.startswith("_"):
                continue
            setattr(args, attr, getattr(sub_args, attr))

        return args


def main():
    root = Command()
    root.add_argument("-v", "--verbose", action="count")

    cmd1 = Command()
    cmd1_foo = Command()
    cmd1_foo.add_argument("-n", "--name")
    cmd1.add_subcommand("foo", cmd1_foo)
    root.add_subcommand("cmd1", cmd1)

    cmd2 = Command()
    cmd2_bar = Command()
    cmd2_bar.add_argument("-s", "--size", type=int)
    cmd2.add_subcommand("bar", cmd2_bar)
    root.add_subcommand("cmd2", cmd2)

    print(root.parse_args())


if __name__ == "__main__":
    main()
