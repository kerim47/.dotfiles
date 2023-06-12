#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(dirname "$(readlink -f "$0")")"
source "$SCRIPT_DIR/fastgdb_definitions"

if ! [ -d "$FASTGDB_DIR" ]; then
    mkdir -p "$FASTGDB_DIR"
else
    echo "error: $FASTGDB_DIR already exists"
    exit 1
fi

if ! [ -f "${FASTGDB_FILE}__default" ]; then
    cat <<EOF > "${FASTGDB_FILE}__default"
g0 = echo "alpha\n"
g1 = echo "beta\n"
g2 = echo "gamma\n"
g3 = echo "delta\n"
g4 = echo "epsilon\n"
g5 = echo "zeta\n"
g6 = echo "eta\n"
g7 = echo "theta\n"
g8 = echo "iota\n"
g9 = echo "kappa\n"
EOF
    ln -s "$FASTGDB_DIR/fastgdb__default" "$FASTGDB_FILE"
    echo "Creating fastgdb template"
else
    echo "fastgdb file already exists"
fi
