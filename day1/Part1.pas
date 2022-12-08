program AOC2022;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}
  cthreads,
  {$ENDIF}
  Classes, SysUtils;

var
  FileInput: TextFile;
  TextLine: String;

  Max: Integer;
  LastCount: Integer;
begin
  AssignFile(FileInput, 'input.txt');

  Max := 0;
  LastCount := 0;

  try
    Reset(FileInput);

    while not EOF(FileInput) do
    begin
      ReadLn(FileInput, TextLine);

      if Length(TextLine) > 0 then
      begin
         LastCount += StrToInt(TextLine);
      end
      else
      begin
        if Max < LastCount then
           Max := LastCount;

        LastCount := 0;
      end;
    end;
  finally
    CloseFile(FileInput);
  end;

  WriteLn(Max);
  ReadLn;
end.

