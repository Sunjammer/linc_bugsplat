package bugsplat;
import cpp.*;

@:keep
@:include('linc_bugsplat.h')
#if !display
@:build(linc.Linc.touch())
@:build(linc.Linc.xml('bugsplat'))
#end
extern class Bugsplat {
    @:native("linc::bugsplat::createSender")
    static function createSender(database:String, application:String, version:String):Pointer<MiniDmpSender>;
} //bugsplat

@:keep
@:include('linc_bugsplat.h')
@:native('MiniDmpSender')
extern class MiniDmpSender { }