'''
Control:
    robot.move_forward()
    robot.rotate_right()
    robot.rotate_left()
    robot.display_color(string)
    robot.finish_round()
Sensors:
    robot.ultrasonic_front() -> int
    robot.ultrasonic_right() -> int
    robot.ultrasonic_left() -> int
    robot.get_color() -> string
'''


def main():
    from queue import LifoQueue
    import copy

    #move robot explorer
    def direction_check(direction_check, direction_look):
        print("d_l:", direction_look)
        print("d_c:", direction_check)
        if direction_check == 'left':
            if direction_look == 'up':
                dir = check_conf(2)
            elif direction_look == 'left':
                dir = check_conf(1)
            elif direction_look == 'down':
                dir = check_conf(4)
            elif direction_look == 'right':
                dir = check_conf(3)
            return dir, 0, 2

        elif direction_check == 'down':
            if direction_look == 'up':
                dir = check_conf(3)
            elif direction_look == 'left':
                dir = check_conf(2)
            elif direction_look == 'down':
                dir = check_conf(1)
            elif direction_look == 'right':
                dir = check_conf(4)
            return dir, 3, 1

        elif direction_check == 'right':
            if direction_look == 'up':
                dir = check_conf(4)
            elif direction_look == 'left':
                dir = check_conf(3)
            elif direction_look == 'down':
                dir = check_conf(2)
            elif direction_look == 'right':
                dir = check_conf(1)
            return dir, 2, 0

        elif direction_check == 'up':
            if direction_look == 'up':
                dir = check_conf(1)
            elif direction_look == 'left':
                dir = check_conf(4)
            elif direction_look == 'down':
                dir = check_conf(3)
            elif direction_look == 'right':
                dir = check_conf(2)
            return dir, 1, 3

    def check_conf(direction):
        if direction == 1:
            if robot.ultrasonic_front() >= 1:
                return True
        elif direction == 2:
            if robot.ultrasonic_left() >= 1:
                return True
        elif direction == 3:
            robot.rotate_left()
            if robot.ultrasonic_left() >= 1:
                return True
            else:
                robot.rotate_right()
        elif direction == 4:
            if robot.ultrasonic_right() >= 1:
                return True
        return False

    #move robot
    def funcions_move(direction):
        if direction == 1:
            robot.move_forward()
        elif direction == 2:
            robot.rotate_left()
            robot.move_forward()
        elif direction == 3:
            robot.rotate_left()
            robot.rotate_left()
            robot.move_forward()
        elif direction == 4:
            robot.rotate_right()
            robot.move_forward()

    def move(direction_look, pos_next, pos):
        posX = pos_next[0] - pos[0]
        posY = pos_next[1] - pos[1]
        print(":::::::::::::")
        print("---pos:", pos)
        print("---pos_next: ", pos_next)
        if posX == 1:
            if direction_look == 'up':
                funcions_move(4)
            elif direction_look == 'left':
                funcions_move(3)
            elif direction_look == 'down':
                funcions_move(2)
            elif direction_look == 'right':
                funcions_move(1)
            direction_look = 'right'
        elif posX == -1:
            if direction_look == 'up':
                funcions_move(2)
            elif direction_look == 'left':
                funcions_move(1)
            elif direction_look == 'down':
                funcions_move(4)
            elif direction_look == 'right':
                funcions_move(3)
            direction_look = 'left'
        elif posY == 1:
            if direction_look == 'up':
                funcions_move(3)
            elif direction_look == 'left':
                funcions_move(2)
            elif direction_look == 'down':
                funcions_move(1)
            elif direction_look == 'right':
                funcions_move(4)
            direction_look = 'down'
        elif posY == -1:
            if direction_look == 'up':
                funcions_move(1)
            elif direction_look == 'left':
                funcions_move(4)
            elif direction_look == 'down':
                funcions_move(3)
            elif direction_look == 'right':
                funcions_move(2)
            direction_look = 'up'
        print("---",direction_look)

        return direction_look, pos_next

    #colors
    def color_count(color, colors):
        match color:
            case 'red':
                colors[0] += 1
            case 'blue':
                colors[1] += 1
            case 'green':
                colors[2] += 1
            case 'cyan':
                colors[3] += 1
            case 'magenta':
                colors[4] += 1
            case 'yellow':
                colors[5] += 1
        return colors

    def color_white(colors, colr, map_color):
        print("--------------------")
        print("Finding color white...")
        for i in range(0, len(colors)):
            if colors[i] == 7:
                color = colr[i]

        for i in range(0, len(map_color)):
            for e in range(0, len(map_color[i])):
                if map_color[i][e] == 'white':
                    print("Color white is ", color)
                    print("Color position:", [e,i])
                    print("--------------------")
                    return [e, i], color

    def find_exit(map_color):
        print("--------------------")
        print("Finding the exit...")
        pos_exit = [0,0]
        #rows
        for list in map_color:
            list_color = []
            colors_num = [0, 0, 0, 0, 0, 0]
            for color in list:
                if color not in list_color and color != 'white':
                    list_color.append(color)
                colors_num = color_count(color, colors_num)

            if len(list_color) >= 6:
                pos_exit[1] += 2
            for num in colors_num:
                if num >= 3:
                    pos_exit[1] += 1

        #cols
        for i in range(0, len(map_color[0])):
            list_color = []
            colors_num = [0, 0, 0, 0, 0, 0]
            for e in range(0,len(map_color)):
                if map_color[e][i] not in list_color and map_color[e][i] != 'white':
                    list_color.append(map_color[e][i])
                colors_num = color_count(map_color[e][i], colors_num)

                if len(list_color) >= 6:
                    pos_exit[0] += 2
                for num in colors_num:
                    if num >= 3:
                        pos_exit[0] += 1
        print("Exit pos")
        print("--------------------")
        return pos_exit

    def DFS_explorer(direction_look, pos, colors):
        # explorer of laberint
        sum_vis = 0
        pos_stack = LifoQueue(maxsize=48)
        map_visited = [[False for i in range(0, 6)] for i in range(0, 8)]
        map_conec = [[['.' for i in range(0, 4)] for i in range(0, 6)] for i in range(0, 8)]
        map_color = [['_' for i in range(0, 6)] for i in range(0, 8)]
        directions = ['right', 'down', 'left', 'up']
        colors_num = [0 for i in range(0, len(colors))]
        print("####################")
        print("starting explorer...")

        while True:

            print("_________")
            for e in map_visited:
                print(e)
            print()
            for e in map_conec:
                print(e)
            print()
            for e in map_color:
                print(e)
            print("_________")

            bool = False
            if not map_visited[pos[1]][pos[0]]:
                map_visited[pos[1]][pos[0]] = True
                sum_vis += 1
                map_color[pos[1]][pos[0]] = robot.get_color()
                robot.display_color(map_color[pos[1]][pos[0]])
                colors_num = color_count(map_color[pos[1]][pos[0]], colors_num)
                for i in range(0, 4):
                    posX = pos[0] + movi[i][0]
                    posY = pos[1] + movi[i][1]
                    if posX > -1 and posX < 6 and posY > -1 and posY < 8:
                        if map_visited[posY][posX] == False:
                            bool, n_ac, n_an = direction_check(directions[i], direction_look)
                            if bool:
                                map_conec[posY][posX][n_ac] = [pos[0], pos[1]]
                                map_conec[pos[1]][pos[0]][n_an] = [posX, posY]
                                print("---", posX, posY, "---")
                            else:
                                map_conec[posY][posX][n_ac] = "_"
                                map_conec[pos[1]][pos[0]][n_an] = "_"

            # stop
            if sum_vis == 6 * 8:
                break

            #move
            bool = False
            for i in range(0, 4):
                posX = pos[0] + movi[i][0]
                posY = pos[1] + movi[i][1]
                if posX > -1 and posX < 6 and posY > -1 and posY < 8:
                    if map_visited[posY][posX] == False and [posX, posY] in map_conec[pos[1]][pos[0]]:
                        print(":", posX, posY, ":")
                        pos_stack.put([pos[0], pos[1]])
                        direction_look, pos = move(direction_look, [posX, posY], pos)
                        bool = True
                        break

            if not bool:
                print("________________")
                print("back")
                pos_old = pos_stack.get()
                direction_look, pos = move(direction_look, pos_old, pos)

        print("####################")
        return direction_look, pos, map_conec, map_color, colors_num

    class item_DFS_S:
        def __init__(self, pos, map_visited, acum_vis, code_pos):
            self.pos = pos
            self.map_visited = map_visited
            self.acum_vis = acum_vis
            self.code_pos = code_pos
    def DFS_move_specific(pos_ini, pos_final, map_conec):
        map_visited = [[False for i in range(0, 6)] for i in range(0, 8)]
        map_visited[pos[1]][pos[0]] = True
        paths = []
        ini_item_white = item_DFS_S(pos_ini, map_visited,  1, 0)
        stack = []
        stack.append(ini_item_white)
        print("####################")
        print("starting DFS...")

        while len(stack) > 0:
            print("________")
            for e in stack:
                print(e.pos)
                #for i in e.map_visited:
                #    print(i)
                print(e.acum_vis)
                print(e.code_pos)
                print()
            print("________")

            item = copy.deepcopy(stack[-1])
            if item.pos == pos_final:
                path = []
                for i in stack:
                    path.append(i.pos)
                paths.append(path)
                stack.pop()
                print("found")
                print(path)
                continue
            bool = False
            for i in range(item.code_pos,4):
                posX = item.pos[0] + movi[i][0]
                posY = item.pos[1] + movi[i][1]
                if posX > -1 and posX < 6 and posY > -1 and posY < 8:
                    if item.map_visited[posY][posX] == False and [posX, posY] in map_conec[item.pos[1]][item.pos[0]]:
                        print("---",posX,posY,"---")
                        stack[-1].code_pos = i + 1
                        item.pos[0] = posX
                        item.pos[1] = posY
                        item.map_visited[posY][posX] = True
                        item.acum_vis += 1
                        stack.append(item)
                        bool = True
                        break
            if not bool:
                stack.pop()

        paths = min(paths)
        print("Paths found: ", paths)
        print("####################")
        return paths

    def move_spefific(path, direction_l, po):
        for pos_next in path:
            direction_l, po = move(direction_l, pos_next, po)
        return direction_l, po

    # incial variables
    movi = [[1, 0], [0, 1], [-1, 0], [0, -1]]
    colors = ['red', 'blue', 'green', 'cyan', 'magenta', 'yellow']

    pos = [5, 0]  # inicial position
    direction_look = 'down'  # inicial look

    # main code
    direction_look, pos, map_conec, map_color, colors_num  = DFS_explorer(direction_look, pos, colors)

    #color white
    pos_white, color_w = color_white(colors_num, colors, map_color)

    #Algorit exit
    pos_exit = find_exit(map_color)

    #DFS white
    paths = DFS_move_specific(pos ,pos_white, map_conec)
    direction_look, pos = move_spefific(paths, direction_look, pos)
    print("##############################")
    print()
    print("El color faltanta es ", color_w)
    print()
    print("##############################")

    #DFS exit
    paths = DFS_move_specific(pos, pos_exit,map_conec)
    direction_look, pos = move_spefific(paths, direction_look, pos)
    print("##############################")
    print()
    print("Salida encontrada")
    print()
    print("##############################")



if __name__ == "__main__":
    main()
