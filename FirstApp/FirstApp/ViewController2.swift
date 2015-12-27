//
//  ViewController2.swift
//  FirstApp
//
//  Created by Shikhar  on 23/10/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

import UIKit
import AVFoundation
class ViewController2: UIViewController {

    var Player:AVAudioPlayer!
    var audioEngine:AVAudioEngine!
    var received:model!
    var file:AVAudioFile!
    override func viewDidLoad() {
        super.viewDidLoad()
        audioEngine=AVAudioEngine()
        var nsfilepath=received.path
        Player = AVAudioPlayer(contentsOfURL: nsfilepath, error: nil)
        Player.enableRate=true
        file=AVAudioFile(forReading: nsfilepath, error: nil)

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func stopPlayback(sender: UIButton) {
        Player.stop()
        Player.currentTime=0.0
        
    }
    @IBAction func playFast(sender: UIButton) {
        Player.stop()
        Player.rate=2.0
        Player.play()
    }

    @IBAction func playSlow(sender: UIButton) {
        Player.stop()
        Player.rate=0.5
        Player.play()
        
        
    }
    
    @IBAction func playChipmunk(sender: UIButton) {
        Player.stop()
        audioEngine.stop()
        audioEngine.reset()
        var audioplayernode=AVAudioPlayerNode()
        audioEngine.attachNode(audioplayernode)
        var effect=AVAudioUnitTimePitch()
        effect.pitch = 1000
        audioEngine.attachNode(effect)
        audioEngine.connect(audioplayernode, to: effect, format: nil)
        audioEngine.connect(effect, to: audioEngine.outputNode, format: nil)
        audioplayernode.scheduleFile(file, atTime: nil, completionHandler: nil)
        audioEngine.startAndReturnError(nil)
        audioplayernode.play()
        
    }
    
    @IBAction func playDarthVader(sender: UIButton) {
        Player.stop()
        audioEngine.stop()
        audioEngine.reset()
        var audioplayernode=AVAudioPlayerNode()
        audioEngine.attachNode(audioplayernode)
        var effect=AVAudioUnitTimePitch()
        effect.pitch = -1000
        audioEngine.attachNode(effect)
        audioEngine.connect(audioplayernode, to: effect, format: nil)
        audioEngine.connect(effect, to: audioEngine.outputNode, format: nil)
        audioplayernode.scheduleFile(file, atTime: nil, completionHandler: nil)
        audioEngine.startAndReturnError(nil)
        audioplayernode.play()

    }
    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
