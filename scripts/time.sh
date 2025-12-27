#!/usr/bin/env bash
set -eu

APP_MALLOC="./build/src/main"
APP_GOVNOLLOC="./build/src/main_malloc"

if [[ ! -x "$APP_MALLOC" ]] || [[ ! -x "$APP_GOVNOLLOC" ]]; then
  echo "Ошибка: Один из файлов не найден или не является исполняемым."
  exit 1
fi

echo "--- Сравнение аллокаторов ---"

echo "Malloc: "
time ("$APP_MALLOC" >/dev/null 2>&1)

echo -e "\nGovnolloc:"
time ("$APP_GOVNOLLOC" >/dev/null 2>&1)
