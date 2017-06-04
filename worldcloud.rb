class Cloud 
    @lines = []
    
    attr_accessor :lines
end

class DataSet
    @words = {  }
    @width = 0
    
    attr_accessor :words, :width
end

data_sets = Array.new

def get_words(count)
    i = 0
    words = {  }
    while i < count do
        line = gets
        w = line.split(' ')[0]
        c = line.split(' ')[1].to_i
        words[w] = c
        i += 1
    end
    return words
end

def most_occurring_word_count(words)
    words.max_by do |key, value|
        value
    end
end

space_pts = 10
clouds = Array.new
while true do
    line = gets
    w = line.split(' ')[0].to_i
    unless w == 0 then
        data_set = DataSet.new
        data_set.width = w
        n = line.split(' ')[1].to_i
        data_set.words = get_words n
        data_sets << data_set
    else 
        break;
    end
end

data_sets.each do |data_set|
    larget_count = (most_occurring_word_count data_set.words)[1]
    cloud = Cloud.new
    cloud.lines = Array.new
    remaining_width_in_line = data_set.width
    line_height = 0
    data_set.words.sort.map do |word, count|
        unless count < 5
            pt = 8 + ((40 * (count - 4)).to_f/(larget_count - 4).to_f).ceil
            width = ((9.0/16.0) * word.length.to_f * pt.to_f).ceil
            

            if ((data_set.width != remaining_width_in_line) && ((width + 10) > remaining_width_in_line) )then
                cloud.lines << line_height
                line_height = 0
                remaining_width_in_line = data_set.width
            end
            
            if remaining_width_in_line == data_set.width then
                remaining_width_in_line -= width
            else
                remaining_width_in_line -= (space_pts + width)
            end
            if pt > line_height then
                line_height = pt
            end
            
        end
    end
    cloud.lines << line_height
    clouds << cloud
end

i = 1
clouds.each do |c|
    sum = c.lines.inject(0, :+)
    puts "CLOUD #{i}: #{sum}"
    i += 1
end