using System;

class Document {
    public string Name;
    public string Author;
    public string[] Keywords;
    public string Theme;
    public string FilePath;

    public Document(string Name, string Author, string[] Keywords, string Theme, string FilePath) {
        this.Name = Name;
        this.Author = Author;
        this.Keywords = Keywords;
        this.Theme = Theme;
        this.FilePath = FilePath;
    }

    public virtual void GetInfo() {
        Console.WriteLine($"Document Name: {Name}");
        Console.WriteLine($"Author: {Author}");
        Console.WriteLine($"Keywords: {string.Join(", ", Keywords)}");
        Console.WriteLine($"Theme: {Theme}");
        Console.WriteLine($"File path: {FilePath}");
    }
}

class MSWord : Document {
    public string Font;

    public MSWord(string Name, string Author, string[] Keywords, string Theme, string FilePath, string Font)
        : base(Name, Author, Keywords, Theme, FilePath) {
        this.Font = Font;
    }
    public override void GetInfo() {
        base.GetInfo();
        Console.WriteLine($"Font: {Font}");
    }
}

class PDF : Document {
    public int PageCount;

    public PDF(string Name, string Author, string[] Keywords, string Theme, string FilePath, int PageCount)
        : base(Name, Author, Keywords, Theme, FilePath) {
        this.PageCount = PageCount;
    }
    public override void GetInfo() {
        base.GetInfo();
        Console.WriteLine($"Page count: {PageCount}");
    }
}

class MSExcel : Document {
    public int Row, Column;

    public MSExcel(string Name, string Author, string[] Keywords, string Theme, string FilePath, int Row, int Column)
        : base(Name, Author, Keywords, Theme, FilePath) {
        this.Row = Row;
        this.Column = Column;
    }
    public override void GetInfo() {
        base.GetInfo();
        Console.WriteLine($"Row count: {Row}");
        Console.WriteLine($"Column count: {Column}");
    }
}

class TXT : Document {
    public int SymbolsCount;

    public TXT(string Name, string Author, string[] Keywords, string Theme, string FilePath, int SymbolsCount)
        : base(Name, Author, Keywords, Theme, FilePath) {
        this.SymbolsCount = SymbolsCount;
    }
    public override void GetInfo() {
        base.GetInfo();
        Console.WriteLine($"Symbols count: {SymbolsCount}");
    }
}

class HTML : Document {
    public string Title;

    public HTML(string Name, string Author, string[] Keywords, string Theme, string FilePath, string Title)
        : base(Name, Author, Keywords, Theme, FilePath) {
        this.Title = Title;
    }
    public override void GetInfo() {
        base.GetInfo();
        Console.WriteLine($"Title: {Title}");
    }
}

class DocumentManager {
    private static DocumentManager Instance;
    private DocumentManager() { }
    public static DocumentManager GetInstance() {
        if (Instance == null) {
            Instance = new DocumentManager();
        }
        return Instance;
    }
    public void ShowInfo(Document document) {
        document.GetInfo();
    }
}

class Program {
    static void Main(string[] args) {
        DocumentManager Manager = DocumentManager.GetInstance();
        bool IsProgramRunning = true;
        int UserChoice;

        while (IsProgramRunning) {
            Console.WriteLine("О каком документе вывести информацию? (введите цифру от 1 до 5)");
            Console.WriteLine("1 | MS Word");
            Console.WriteLine("2 | PDF");
            Console.WriteLine("3 | MS Excel");
            Console.WriteLine("4 | TXT");
            Console.WriteLine("5 | HTML");
            Console.WriteLine("0 | Выход из программы");
            Console.WriteLine();

            UserChoice = Convert.ToInt32(Console.ReadLine());

            switch (UserChoice) {
                case 0:
                    IsProgramRunning = false;
                    break;
                case 1:
                    Console.WriteLine();
                    Document SomeWordDocument = new MSWord("123", "Konstantin", new string[] { "word", "document" }, "drawing", "C:/Документы/Word.docx", "Calibri");
                    Manager.ShowInfo(SomeWordDocument);
                    Console.WriteLine();
                    break;
                case 2:
                    Console.WriteLine();
                    Document SomePDFDocument = new PDF("pi-231", "Alex", new string[] { "pdf", "document" }, "dancing", "C:/Документы/PDF.pdf", 37);
                    Manager.ShowInfo(SomePDFDocument);
                    Console.WriteLine();
                    break;
                case 3:
                    Console.WriteLine();
                    Document SomeExcelDocument = new MSExcel("work", "Aleksandr", new string[] { "excel", "document" }, "programming", "C:/Документы/Excel.xls", 2, 4);
                    Manager.ShowInfo(SomeExcelDocument);
                    Console.WriteLine();
                    break;
                case 4:
                    Console.WriteLine();
                    Document SomeTXTDocument = new TXT("schedule", "Artem", new string[] { "txt", "document" }, "singing", "C:/Документы/txt.txt", 101142);
                    Manager.ShowInfo(SomeTXTDocument);
                    Console.WriteLine();
                    break;
                case 5:
                    Console.WriteLine();
                    Document SomeHTMLDocument = new HTML("c#", "Gennadiy", new string[] { "html", "document" }, "cybersport", "C:/Документы/HTML.html", "node js");
                    Manager.ShowInfo(SomeHTMLDocument);
                    Console.WriteLine();
                    break;
                default:
                    Console.WriteLine();
                    Console.WriteLine("Ваша цифра не подходит под ограничение");
                    Console.WriteLine();
                    break;
            }
        }
    }
}
