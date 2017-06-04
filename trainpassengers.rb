class StationInput
    @in = 0
    @out = 0
    @waiting = 0

    attr_accessor :in, :out, :waiting
end
first_line = gets
capacity = first_line.split(' ')[0].to_i
station_count = first_line.split(' ')[1].to_i

i = 0
inputs = Array.new
while i < station_count do 
    input = StationInput.new
    line = gets
    input.out = line.split(' ')[0].to_i
    input.in = line.split(' ')[1].to_i
    input.waiting = line.split(' ')[2].to_i
    inputs << input
    i += 1
end 

remaining_seats = capacity
currently_seated = 0
is_valid = true;
inputs.each_with_index do |input, i|
    if input.out > currently_seated then
        puts "impossible"
        is_valid = false
        break;
    elsif input.in > (remaining_seats + input.out) then
        puts "impossible"
        is_valid = false
        break;
    else
        remaining_seats = capacity - (currently_seated - input.out + input.in)
        if remaining_seats != 0 && input.waiting != 0 then
            puts "impossible"
            is_valid = false
            break;
        end
        currently_seated = capacity - remaining_seats
    end
end
if is_valid && currently_seated > 0 then
    puts "impossible"
elsif is_valid then
    puts "possible"
end