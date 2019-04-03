class Bike
    @front_cluster = nil
    @rear_cluster = nil

    attr_accessor :front_cluster, :rear_cluster

    def get_all_drive_ratios
        all_ratios = Array.new
        @front_cluster.sprockets.each do |front_sprocket|
            @rear_cluster.sprockets.each do |rear_sprocket|
                all_ratios << (rear_sprocket.no_of_teeth / front_sprocket.no_of_teeth)
            end
        end
        return all_ratios
    end
end

class Cluster
    @sprocket_count = 0
    @sprockets = Array.new

    attr_accessor :sprocket_count, :sprockets
end

class Sprocket
    @no_of_teeth = 0

    attr_accessor :no_of_teeth
end

bikes = Array.new

input_string = gets
while !input_string.start_with?("0") do
    bike = Bike.new
    front_cluster = Cluster.new
    rear_cluster = Cluster.new
    front_cluster.sprocket_count = input_string.split(' ')[0].to_i
    rear_cluster.sprocket_count = input_string.split(' ')[1].to_i
    front_cluster.sprockets = Array.new
    rear_cluster.sprockets = Array.new
    input_string = gets.split(' ')
    input_string.each do |t|
        sprocket = Sprocket.new
        sprocket.no_of_teeth = t.to_f
        front_cluster.sprockets << sprocket
    end
    input_string = gets.split(' ')
    input_string.each do |t|
        sprocket = Sprocket.new
        sprocket.no_of_teeth = t.to_f
        rear_cluster.sprockets << sprocket
    end
    bike.front_cluster = front_cluster
    bike.rear_cluster = rear_cluster
    bikes << bike
    input_string = gets
end

bikes.each do |bike|
    all_ratios = bike.get_all_drive_ratios
    all_ratios = all_ratios.sort.uniq
    max_spread = -1
    all_ratios.each_with_index do |ratio, i|
        unless i == (all_ratios.length - 1) then
            spread = all_ratios[i+1] / ratio
            if spread > max_spread then
                max_spread = spread
            end
        end
    end
    puts sprintf('%.2f', max_spread.round(2))
end