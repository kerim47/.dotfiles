import curses

def main(stdscr):
    # Terminal boyutunu al
    height, width = stdscr.getmaxyx()

    # Margin hesaplama
    margin = 2
    inner_width = width - 2 * margin
    inner_height = height - 2 * margin

    # İçerik oluşturma
    outer_box = '+' + '-' * (width - 2) + '+'
    inner_box = '|' + ' ' * (width - 2) + '|'
    content = [' ' * inner_width] * inner_height

    # İçeriği çiz
    stdscr.addstr(margin, margin, outer_box)
    for i, line in enumerate(content):
        stdscr.addstr(i + margin + 1, margin, inner_box)
    stdscr.addstr(height - margin - 1, margin, outer_box)

    # Ekranda tutun
    stdscr.refresh()
    stdscr.getch()

# curses uygulamasını başlat
curses.wrapper(main)

