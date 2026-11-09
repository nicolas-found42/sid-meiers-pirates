#!/bin/sh
# VC7.1 (cl 13.10.3077) runner for byte-matching, per docs/TOOLCHAIN.md.
# The toolchain lives outside the tracked tree under analysis/toolchain/
# (gitignored); no Microsoft payload is committed.
#
# Sets the isolated prefix and silences Wine, then execs the original
# compiler. The harness passes {src}/{obj} as Z:-mapped Windows paths
# (path_style "wine").
set -eu

ROOT="$(cd "$(dirname "$0")/../analysis/toolchain" && pwd)"

# Parallel census workers isolate prefixes; tools/compare_census.py sets
# PIRATES_WINEPREFIX per unit. The default stays the proven prefix2.
export WINEPREFIX="${PIRATES_WINEPREFIX:-$ROOT/prefix2}"
export WINEDEBUG="-all"

exec "$ROOT/wine/mach9/wine/bin/wine" "$ROOT/vc71/bin/cl.exe" "$@"
