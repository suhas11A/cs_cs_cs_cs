#!/usr/bin/env bash
P1=${1:-./a.out}
P2=${2:-./sieve}

diffs=0
for i in $(seq 2 1000); do
  o1="$({ echo "$i"; } | "$P1")"
  o2="$({ echo "$i"; } | "$P2")"
  if [ "$o1" != "$o2" ]; then
    echo "❌ Diff at $i"
    echo "  $P1: $o1"
    echo "  $P2: $o2"
    diffs=$((diffs+1))
  fi
done

if [ $diffs -eq 0 ]; then
  echo "✅ No differences for inputs 2..1000."
else
  echo "Total diffs: $diffs"
fi
