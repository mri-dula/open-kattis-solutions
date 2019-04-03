x_axis = ['x', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'] 

test_cases = []
count = gets.to_i
for i in 1..count do 
    line = gets
    w = line.split
    test_case = []
    current_position = []
    w.each_with_index do |char, i|
        index = i + 1
        if index % 2 == 1 then 
            current_position << char
        else
            current_position << char
            if [ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' ].include?(char) then 
                current_position.reverse!
            end
            current_position[0] = x_axis.find_index current_position[0]
            current_position[1] = current_position[1].to_i
            test_case << current_position
            current_position = []
        end
    end
    test_cases << test_case
end

test_cases.each do |test_case|
    start = test_case[0]
    finish = test_case[1]
    if start == finish then 
        puts "0 #{x_axis[start[0]]} #{start[1]}"
    else
        all_four_routes_from_start = []
        route = []
        next_position = start
        while (next_position[0] - 1) > 0 && (next_position[1] - 1) > 0 do 
            route << [ next_position[0] - 1, next_position[1] - 1 ]
            next_position = [ next_position[0] - 1, next_position[1] - 1 ]
        end
        all_four_routes_from_start << route

        route = []
        next_position = start
        while (next_position[0] + 1) < 9 && (next_position[1] - 1) > 0 do 
            route << [ next_position[0] + 1, next_position[1] - 1 ]
            next_position = [ next_position[0] + 1, next_position[1] - 1 ]
        end
        all_four_routes_from_start << route

        route = []
        next_position = start
        while (next_position[0] - 1) > 0 && (next_position[1] + 1) < 9 do 
            route << [ next_position[0] - 1, next_position[1] + 1 ]
            next_position = [ next_position[0] - 1, next_position[1] + 1 ]
        end
        all_four_routes_from_start << route

        route = []
        next_position = start
        while (next_position[0] + 1) < 9 && (next_position[1] + 1) < 9 do 
            route << [ next_position[0] + 1, next_position[1] + 1 ]
            next_position = [ next_position[0] + 1, next_position[1] + 1 ]
        end
        all_four_routes_from_start << route

        all_four_routes_from_finish = []
        route = []
        next_position = finish
        while (next_position[0] - 1) > 0 && (next_position[1] - 1) > 0 do 
            route << [ next_position[0] - 1, next_position[1] - 1 ]
            next_position = [ next_position[0] - 1, next_position[1] - 1 ]
        end
        all_four_routes_from_finish << route

        route = []
        next_position = finish
        while (next_position[0] + 1) < 9 && (next_position[1] - 1) > 0 do 
            route << [ next_position[0] + 1, next_position[1] - 1 ]
            next_position = [ next_position[0] + 1, next_position[1] - 1 ]
        end
        all_four_routes_from_finish << route

        route = []
        next_position = finish
        while (next_position[0] - 1) > 0 && (next_position[1] + 1) < 9 do 
            route << [ next_position[0] - 1, next_position[1] + 1 ]
            next_position = [ next_position[0] - 1, next_position[1] + 1 ]
        end
        all_four_routes_from_finish << route

        route = []
        next_position = finish
        while (next_position[0] + 1) < 9 && (next_position[1] + 1) < 9 do 
            route << [ next_position[0] + 1, next_position[1] + 1 ]
            next_position = [ next_position[0] + 1, next_position[1] + 1 ]
        end
        all_four_routes_from_finish << route

        turning_point = []
        all_four_routes_from_finish.each do |finish_route|
            if finish_route.include? start then 
                turning_point = finish
            end
        end
        if turning_point.any? then 
            puts "1 #{x_axis[start[0]]} #{start[1]} #{x_axis[finish[0]]} #{finish[1]}"
        else
            all_four_routes_from_start.each do |start_route|
                all_four_routes_from_finish.each do |finish_route|
                    if (start_route & finish_route).any? then 
                        turning_point = start_route & finish_route
                    end
                end
            end
            if turning_point.any? then 
                turning_point = turning_point[0]
                puts "2 #{x_axis[start[0]]} #{start[1]} #{x_axis[turning_point[0]]} #{turning_point[1]} #{x_axis[finish[0]]} #{finish[1]}"
            else
                puts "Impossible"
            end
        end
    end
end