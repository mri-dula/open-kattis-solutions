lines = gets(nil)
lines = lines.split("\n")

class WordsHelper
    def self.words
        {
            0 => 'zero',
            1 => 'one',
            2 => 'two',
            3 => 'three',
            4 => 'four',
            5 => 'five',
            6 => 'six',
            7 => 'seven',
            8 => 'eight',
            9 => 'nine',
            10 => 'ten',
            11 => 'eleven',
            12 => 'twelve',
            13 => 'thirteen',
            14 => 'fourteen',
            15 => 'fifteen',
            16 => 'sixteen',
            17 => 'seventeen',
            18 => 'eighteen',
            19 => 'nineteen',
            20 => 'twenty',
            30 => 'thirty',
            40 => 'forty',
            50 => 'fifty',
            60 => 'sixty',
            70 => 'seventy',
            80 => 'eighty',
            90 => 'ninety'
        }
    end

    def self.get_word_from_number(n) 
        if self.words.key? n then
            self.words[n]
        else
            result = self.words[(n/10)*10] + '-'
            result = result + self.words[n%10]
        end
    end
end

lines.each  do |line|
    numbers = Array.new
    lineUnderReconstruction = line
    while(true) do
        m = lineUnderReconstruction.match(/\d+/)
        if m then
            i = m.offset(0)[0]
            word = WordsHelper.get_word_from_number(m.to_s.to_i)
            if i == 0 then
                word = word.capitalize
            end
            lineUnderReconstruction = lineUnderReconstruction.sub(m.to_s, word)
        else
            puts lineUnderReconstruction
            break
        end
        
        #numbers << [n, $~.offset(0)[0]]
    end
end

