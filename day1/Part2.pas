program AOC2022;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}
  cthreads,
  {$ENDIF}
  Classes, SysUtils;

procedure Swap(var A, B: Integer);
var
  Temp: Integer;
begin
  Temp := A;
  A := B;
  B := Temp;
end;

var
  FileInput: TextFile;
  TextLine: String;

  Top1: Integer;
  Top2: Integer;
  Top3: Integer;
  LastCount: Integer;
begin
  AssignFile(FileInput, 'input.txt');

  Top1 := 0;
  Top2 := 0;
  Top3 := 0;
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
        if Top1 < LastCount then
        begin
           Swap(Top2, Top3);
           Top2 := Top1;
           Top1 := LastCount;
        end
        else if Top2 < LastCount then
        begin
           Swap(Top2, Top3);
           Top2 := LastCount;
        end
        else if Top3 < LastCount then
        begin
           Top3 := LastCount;
        end;

        LastCount := 0;
      end;
    end;
  finally
    CloseFile(FileInput);
  end;

  WriteLn(Top1 + Top2 + Top3);
  ReadLn;
end.

