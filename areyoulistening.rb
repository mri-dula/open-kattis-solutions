class Position 
    attr_accessor :x, :y

    def initialize(x, y)
        @x = x
        @y = y
    end

end
class ListeningDevice
    attr_accessor :range, :position, :id

    def initialize(id, range, position)
        @range = range
        @position = position
        @id = id
    end

    def get_distance_from(position)
        Math.sqrt(((position.x - @position.x) ** 2) + ((position.y - @position.y) ** 2))
    end
end

class BroadcastingDevice
    attr_accessor :position
    def initialize(position) 
        @position = position
    end

    def get_maximum_possible_range_from(other_devices)
        max_range = 0
        other_devices = other_devices.sort_by { |x| x.get_distance_from(self.position) - x.range }
        third_device = other_devices[2]
        if third_device.get_distance_from(self.position) - third_device.range  > 0 then 
            max_range = third_device.get_distance_from(self.position) - third_device.range
        else
            max_range = 0
        end
        if max_range <= 0 then
            max_range = 0
        end
        
        max_range
    end
end

line = gets.split.map { |x| x.to_i }
my_device = BroadcastingDevice.new(Position.new line[0], line[1])
other_devices = []
for i in 1..line[2] do 
    line = gets.split.map { |x| x.to_i}
    other_device = ListeningDevice.new(i, line[2], Position.new(line[0], line[1]))
    other_devices << other_device
end
p my_device.get_maximum_possible_range_from(other_devices).to_i
