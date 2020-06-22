'''
This is a solution in Python for https://open.kattis.com/problems/includescoring
'''
import math


SCORES = [-1, 100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1]

class Participant:

    def __init__(self, problems_solved, penalty, submit_timestamp, extra_point):
        self.problems_solved = problems_solved
        self.penalty = penalty
        self.submit_timestamp = submit_timestamp
        self.extra_point = extra_point
        self.rank = None
        self.score = None

    def is_tied_with(self, participant):
        return self.problems_solved == participant.problems_solved \
            and self.penalty == participant.penalty \
            and self.submit_timestamp == participant.submit_timestamp
        
class Contest:

    def __init__(self):
        self.participants = []

    def score_by_rank(self, rank):
        return 0 if rank > 30 else SCORES[rank]

    def assign_ranks(self):
        sorted_participants = sorted(self.participants, key=lambda t: (-t.problems_solved, t.penalty, t.submit_timestamp))
        current_rank = 1
        previous_participant = None
                
        for participant in sorted_participants:
            if previous_participant == None:
                participant_rank = current_rank
            else:
                if participant.is_tied_with(previous_participant):
                    participant_rank = previous_participant.rank
                else:
                    participant_rank = current_rank

            current_rank = current_rank + 1

            participant.rank = participant_rank
            previous_participant = participant

    def assign_scores(self):
        self.assign_ranks()
        tied_participants = []
        previous_participant = None
        participant_list = [participant for participant in self.participants]
        participant_list.sort(key=lambda x: x.rank)
        for participant in participant_list:
            participant.score = self.score_by_rank(participant.rank) + participant.extra_point
            if previous_participant == None:
                tied_participants.append(participant)
            else:
                if previous_participant.rank == participant.rank:
                    tied_participants.append(participant)
                else:
                    tied_participants = [participant]
                if len(tied_participants) > 1:
                    total_scores = sum([(self.score_by_rank(tied_rank)) for tied_rank in range(participant.rank, participant.rank + len(tied_participants))])
                    average_score = int(math.ceil((total_scores * 1.0)/len(tied_participants)))
                    for tied_participant in tied_participants:
                        tied_participant.score = average_score + tied_participant.extra_point
            previous_participant = participant

    def print_scores(self):
        for participant in self.participants:
            print participant.score

participant_count = 0
contest = Contest()
while True:
    line = raw_input()
    if participant_count == 0:
        participant_count = int(line)
        continue
    args = [int(arg) for arg in line.split(' ')]
    contest.participants.append(Participant(*args))
    if len(contest.participants) == participant_count:
        break

    
contest.assign_scores()
contest.print_scores()
