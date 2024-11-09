
class Pipeline:
    __cmd = None

    def __init__(self, flows):
        def cmd(initial):
            state = initial
            for flow in flows:
                flow(state)
        
        self.__cmd = cmd
    
    def exec_cmd(self, initial):
        self.__cmd(initial)


class Task:
    __pipeline = None
    __initial = None

    def __init__(self, pipeline: Pipeline, init):
        self.__pipeline = pipeline
        self.__initial = init

    
    def exec(self):
        self.__pipeline.exec_cmd(self.__initial)


class Progression:
    __tasks = None
    __task_cnt = 0
    __active_task = 0

    def __init__(self, tasks: list[Task]):
        self.__tasks = tasks
        self.__task_cnt = len(tasks)
    
    def __render_progress(self):
        prelude = 'Tasks: '
        if self.__active_task != self.__task_cnt:
            print(f"{prelude}{self.__active_task}/{self.__task_cnt}")
        else:
            print(f"{prelude}Complete\a")

    def exec_all(self):
        self.__render_progress()
        for task in self.__tasks:
            task.exec()
            self.__active_task += 1
            self.__render_progress()